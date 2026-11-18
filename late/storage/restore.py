from pathlib import Path
import subprocess, os, json, time, hashlib, threading

root = Path('/workspace/p1507-storage')
stage, restore = root / 'staging', root / 'restore-2'
assert not restore.exists()
assert not any(os.environ.get(k) for k in [
    'GIT_OBJECT_DIRECTORY', 'GIT_ALTERNATE_OBJECT_DIRECTORIES',
    'GIT_COMMON_DIR', 'GIT_DIR', 'GIT_WORK_TREE'])
expected = json.loads((root / 'full-inventory.json').read_text())
samples, stop = [], threading.Event()

def sample():
    while not stop.is_set():
        s = os.statvfs(root)
        samples.append(dict(time=time.monotonic(),
                            free_bytes=s.f_bavail * s.f_frsize,
                            free_inodes=s.f_favail))
        stop.wait(.1)

t = threading.Thread(target=sample)
t.start()
start = time.monotonic()
cmd = ['git', 'clone', '--depth=1', '--single-branch', '--no-tags',
       '--no-local', '--branch', 'archive/p1507-20261118',
       'https://github.com/wakairo/NewLang_Evidence.git', str(restore)]
try:
    r = subprocess.run(cmd, capture_output=True,
                       env=dict(os.environ, GIT_TERMINAL_PROMPT='0',
                                GCM_INTERACTIVE='never'), timeout=90)
finally:
    stop.set()
    t.join()
clone_seconds = time.monotonic() - start
(root / 'clone-2.stdout').write_bytes(r.stdout)
(root / 'clone-2.stderr').write_bytes(r.stderr)
(root / 'restore-2-space-samples.json').write_text(json.dumps(samples, indent=2) + '\n')
(root / 'clone-2-time.json').write_text(json.dumps(dict(
    exit=r.returncode, seconds=clone_seconds, command=cmd), indent=2) + '\n')
assert r.returncode == 0

start = time.monotonic()
def git(*args):
    return subprocess.check_output(['git', *args], cwd=restore).decode().strip()

head, tree = git('rev-parse', 'HEAD'), git('rev-parse', 'HEAD^{tree}')
assert head == 'eee78c7a1b8e037ffc62a8c7a138a8602ca3171e'
assert tree == '5fd4239c416125244f060d7543fea9e69b45299c'
assert git('rev-parse', '--is-shallow-repository') == 'true'
assert not (restore / '.git/objects/info/alternates').exists()
assert not (restore / '.git/objects/info/http-alternates').exists()
actual = []
for p in sorted(restore.rglob('*')):
    rel = p.relative_to(restore)
    if rel.parts[0] == '.git':
        continue
    assert not p.is_symlink()
    if not p.is_file():
        continue
    b = p.read_bytes()
    actual.append(dict(path=str(rel), size=len(b),
                       sha256=hashlib.sha256(b).hexdigest(),
                       executable=bool(p.stat().st_mode & 0o111)))
assert actual == expected
tracked = subprocess.check_output(['git', 'ls-files', '-z'], cwd=restore).decode().strip('\x00').split('\x00')
assert sorted(tracked) == sorted(x['path'] for x in expected)
manifest = json.loads((restore / 'MANIFEST.json').read_text())
assert len(manifest) == 243
for row in manifest:
    assert row['path'].startswith('p1507/')
    p = restore / row['path']
    b = p.read_bytes()
    assert len(b) == row['size'] and hashlib.sha256(b).hexdigest() == row['sha256']
    original = Path(row['origin'])
    assert original.is_relative_to('/workspace/p1507-evidence') and not original.is_symlink()
    assert original.read_bytes() == b
    assert bool(original.stat().st_mode & 0o111) == row['executable']
for path, digest in [
    ('p1507/first/A-direct-zero.nl', 'b60e282c828c36bcfcb9353b812810e40a787b2d2ed04a5e11f6b0cb6b089793'),
    ('p1507/first/B-direct-index-one.nl', 'dd7ac7112c3962036c631b6b1b909a3795dda972fa3ebe07939d78da5911666b')]:
    assert hashlib.sha256((restore / path).read_bytes()).hexdigest() == digest
assert subprocess.check_output(['git', '-C', '/workspace/NewLang_Compiler',
                                'rev-parse', 'HEAD']).decode().strip() == '7591848bd7f4bf8967dffd4be8d360e1901a3f06'
verify_seconds = time.monotonic() - start
raw = (json.dumps(actual, indent=2) + '\n').encode()
assert raw == (root / 'full-inventory.json').read_bytes()
(root / 'restored-inventory.json').write_bytes(raw)
def du(p):
    return int(subprocess.check_output(['du', '-s', '-B1', str(p)]).decode().split()[0])
resources = {}
for name, p in [('stage', stage), ('first_restore', root / 'restore'), ('restore', restore)]:
    resources[name] = dict(
        du_bytes=du(p), git_du_bytes=du(p / '.git'),
        index_bytes=(p / '.git/index').stat().st_size,
        packs={f.name: f.stat().st_size for f in (p / '.git/objects/pack').glob('*') if f.is_file()},
        object_counts=subprocess.check_output(['git', 'count-objects', '-v'], cwd=p).decode(),
        path_entries=sum(1 for _ in p.rglob('*')) + 1)
s = os.statvfs(root)
receipt = dict(
    state='FULL_FRESH_REMOTE_RESTORE_PASS', commit=head, tree=tree,
    ref='archive/p1507-20261118', tracked_files=len(actual),
    tracked_bytes=sum(x['size'] for x in actual), payload_files=len(manifest),
    inventory_sha256=hashlib.sha256(raw).hexdigest(),
    manifest_sha256=hashlib.sha256((restore / 'MANIFEST.json').read_bytes()).hexdigest(),
    readme_sha256=hashlib.sha256((restore / 'README.md').read_bytes()).hexdigest(),
    clone_seconds=clone_seconds, full_read_verify_seconds=verify_seconds,
    source_originals_recompared=True, shallow=True, alternates=False,
    https_remote=True, resources=resources,
    free_bytes=s.f_bavail*s.f_frsize, free_inodes=s.f_favail, deletion_yet=False)
(root / 'restore-receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
print(json.dumps(receipt, indent=2))

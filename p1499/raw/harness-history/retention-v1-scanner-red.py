from pathlib import Path, PurePosixPath
import hashlib, json, os, tarfile, io, subprocess, tempfile, urllib.request, urllib.error, shutil
REPO=Path('/workspace/NewLang_Compiler')
RAW=Path('/workspace/p1499-evidence')
HEAD='cd37be844a2ea4b1b41cdd7332927ff72f314d4a'
TOKEN=os.environ['NEWLANG_RELEASE_PAT']
class NoRedirect(urllib.request.HTTPRedirectHandler):
    def redirect_request(self,*args,**kwargs): return None
opener=urllib.request.build_opener(NoRedirect())
def api(path, data=None):
    req=urllib.request.Request('https://api.github.com/repos/wakairo/NewLang_Compiler/'+path,
        data=None if data is None else json.dumps(data).encode(),
        headers={'Authorization':'Bearer '+TOKEN,'Accept':'application/vnd.github+json','Content-Type':'application/json'})
    with opener.open(req,timeout=60) as r: return json.load(r)
def sha(path):
    h=hashlib.sha256()
    with path.open('rb') as f:
        for b in iter(lambda:f.read(1024*1024),b''): h.update(b)
    return h.hexdigest()
def capacity():
    s=os.statvfs('/workspace');return {'free_bytes':s.f_frsize*s.f_bavail,'free_inodes':s.f_favail}
assert api('git/ref/heads/p1499-usize-call-composition')['object']['sha']==HEAD
x=json.loads((RAW/'provenance.json').read_text())
x['local_status']='Selected GCC/ASan+LSan/UBSan PASS; retained GCC 1098/1124 PASS, 26 RED (24 inherited output directory collisions, 2 precommit Git HEAD mismatches). Local attempts exhausted; no rerun. Same-head CI pending; review pending.'
x['storage_inventory']={'A':'All implementation/tests/oracles in pushed origin/p1499-usize-call-composition at HEAD; no local-only history or Git bundle prerequisite.','B':'Own FIRST/RED, all raw compiler/native/CTest outputs, ELF/config snapshots, original v1 and forward sources. Included below.','C':'Only CMakeFiles objects/driver cache and static .a libraries omitted as fully regenerable; symlinks not followed.','D':'Active source Git repository, .venv tools and single verified pinned SDK retained. No independent F/R or old evidence/Git/LFS directory included or deleted.'}
(RAW/'provenance.json').write_text(json.dumps(x,indent=2)+'\n')
shutil.copy2('/workspace/p1499-retain.py',RAW/'retention-script.py')
files={}
omitted=[]
for prefix,root in [('raw',RAW),('build-frontend',REPO/'build-frontend'),('build-asan',REPO/'build-p1499-asan'),('build-ubsan',REPO/'build-p1499-ubsan')]:
    for p in sorted(root.rglob('*')):
        rel=p.relative_to(root)
        if p.is_symlink(): omitted.append(prefix+'/'+str(rel));continue
        if not p.is_file(): continue
        if '.git' in rel.parts: raise RuntimeError('unexpected Git directory in selected build evidence')
        if prefix!='raw' and (('CMakeFiles' in rel.parts and p.name!='CMakeConfigureLog.yaml') or p.suffix in ('.o','.a')): continue
        files[prefix+'/'+rel.as_posix()]=p
manifest={}
for name,p in files.items():
    # Targeted credential exclusion; no raw environment/header/credential files.
    prior=b''
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1024*1024),b''):
            data=prior+b
            if TOKEN.encode() in data or b'-----BEGIN PRIVATE KEY-----' in data:
                raise RuntimeError('credential detected in selected member: '+name)
            prior=data[-max(len(TOKEN),64):]
    manifest[name]={'size':p.stat().st_size,'sha256':sha(p)}
manifest_data=(json.dumps({'head':HEAD,'base':x['base'],'tree':x['tree'],'members':manifest,'omitted_symlinks':omitted},indent=2)+'\n').encode()
arc=Path('/workspace/p1499-cd37be8-evidence.tar.gz')
with tarfile.open(arc,'w:gz',compresslevel=6) as t:
    ti=tarfile.TarInfo('manifest.json');ti.size=len(manifest_data);ti.mode=0o644;t.addfile(ti,io.BytesIO(manifest_data))
    for name,p in files.items():
        ti=t.gettarinfo(str(p),arcname=name);ti.uid=ti.gid=0;ti.uname=ti.gname=''
        with p.open('rb') as f: t.addfile(ti,f)
outer_sha=sha(arc);outer_size=arc.stat().st_size
assert outer_size<512*1024**2
print(json.dumps({'archive_size':outer_size,'sha256':outer_sha,'members':len(files)+1,'uncompressed_bytes':sum(v['size'] for v in manifest.values()),'headroom':capacity()}),flush=True)
release=api('releases',{'tag_name':'p1499-evidence-cd37be8-20261117','target_commitish':HEAD,'name':'Development evidence archive — P1499 C1122 cd37be8','body':'P-owned original FIRST/RED and forward capability/native/OOM/CTest evidence for Issue #1499 / DRAFT PR #1501. Includes local retained regression REDs and provenance limits. Development evidence, not a product release. SHA256 '+outer_sha+'; bytes '+str(outer_size)+'. Staged draft; no product publication.','draft':True,'prerelease':True,'make_latest':'false'})
assert release['draft'] and release['published_at'] is None
rid=release['id'];name='p1499-cd37be8-'+outer_sha[:16]+'.tar.gz'
req=urllib.request.Request(f'https://uploads.github.com/repos/wakairo/NewLang_Compiler/releases/{rid}/assets?name={name}',data=arc.read_bytes(),headers={'Authorization':'Bearer '+TOKEN,'Accept':'application/vnd.github+json','Content-Type':'application/octet-stream'},method='POST')
with opener.open(req,timeout=120) as response:
    assert response.status==201
    asset=json.load(response)
meta=api('releases/'+str(rid))
a=next(a for a in meta['assets'] if a['id']==asset['id'])
assert meta['draft'] and a['name']==name and a['size']==outer_size and a['state']=='uploaded'
assert a.get('digest') in (None,'sha256:'+outer_sha)
clean=Path(tempfile.mkdtemp(prefix='p1499-restore-',dir='/workspace'))
download=clean/'download.tar.gz'
config='header = "Authorization: Bearer '+TOKEN+'"\nheader = "Accept: application/octet-stream"\n'
# curl strips Authorization on cross-host redirects; no signed URL/header saved.
r=subprocess.run(['curl','--config','-','-fsSL',f'https://api.github.com/repos/wakairo/NewLang_Compiler/releases/assets/{a["id"]}','-o',str(download)],input=config.encode(),capture_output=True)
if r.returncode: raise RuntimeError('actual archive download failed: curl exit '+str(r.returncode))
assert download.stat().st_size==outer_size and sha(download)==outer_sha
extracted=clean/'extracted';extracted.mkdir()
with tarfile.open(download,'r:gz') as t:
    members=t.getmembers();names=[m.name for m in members]
    assert len(names)==len(set(names)) and set(names)==set(manifest)|{'manifest.json'}
    assert t.extractfile('manifest.json').read()==manifest_data
    for m in members:
        path=PurePosixPath(m.name)
        assert m.isfile() and not path.is_absolute() and '..' not in path.parts and path.parts
        dest=extracted.joinpath(*path.parts);dest.parent.mkdir(parents=True,exist_ok=True)
        with t.extractfile(m) as inp,dest.open('wb') as out: shutil.copyfileobj(inp,out)
        expected={'size':len(manifest_data),'sha256':hashlib.sha256(manifest_data).hexdigest()} if m.name=='manifest.json' else manifest[m.name]
        assert dest.stat().st_size==expected['size'] and sha(dest)==expected['sha256']
# Actual source restoration, including added files: apply the preserved patch
# to preserved canonical base files, then compare all final files byte-for-byte.
base=extracted/'raw/base'
patch=extracted/'raw/change.patch'
for flags in (['--check'],[]):
    rr=subprocess.run(['git','-C',str(base),'apply',*flags,str(patch)],capture_output=True)
    assert rr.returncode==0, 'restored Git patch application failed'
for p in (extracted/'raw/sources').rglob('*'):
    if p.is_file(): assert p.read_bytes()==(base/p.relative_to(extracted/'raw/sources')).read_bytes()
receipt={'release_id':rid,'release_url':meta['html_url'],'asset_id':a['id'],'asset_name':name,'asset_api_url':a['url'],'bytes':outer_size,'sha256':outer_sha,'members_verified':len(members),'head':HEAD,'tree':x['tree'],'base':x['base'],'fresh_restore':True,'all_member_size_sha_readback':True,'safe_extraction':True,'source_patch_restoration_matches_HEAD_snapshot':True,'git_bundle':'N/A; no local-only Git history, remote branch SHA authenticated before archive','draft':True,'published_at':None,'original_dir':str(RAW),'local_archive':str(arc),'clean_restore_dir':str(clean),'deletion_gate':'restore PASS; awaiting durable Issue receipt before deletion','capacity':capacity()}
Path('/workspace/p1499-retention-receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
print(json.dumps(receipt,indent=2),flush=True)

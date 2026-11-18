import argparse,json,pathlib,subprocess,time,sys
R=pathlib.Path('/workspace/p1528-gate0')
p=argparse.ArgumentParser();p.add_argument('--label',required=True);p.add_argument('--build',action='store_true');p.add_argument('--native-compile',action='store_true');p.add_argument('--native',action='store_true');p.add_argument('argv',nargs=argparse.REMAINDER);a=p.parse_args()
rows=json.loads((R/'ledger.json').read_text());assert len(rows)<48
assert sum(x.get('build',False) for x in rows)+a.build<=2
assert sum(x.get('native_compile',False) for x in rows)+a.native_compile<=2
assert sum(x.get('native',False) for x in rows)+a.native<=6
argv=a.argv[1:] if a.argv[0]=='--' else a.argv
n=len(rows)+1;row=dict(id=n,label=a.label,argv=argv,build=a.build,native_compile=a.native_compile,native=a.native,status='STARTED',time=time.time());rows.append(row);(R/'ledger.json').write_text(json.dumps(rows,indent=2)+'\n')
t=time.monotonic();r=subprocess.run(argv,capture_output=True)
for suffix,b in [('stdout',r.stdout),('stderr',r.stderr)]: (R/'logs'/f'{n:02d}.{suffix}').write_bytes(b)
row.update(status='FINISHED',exit=r.returncode,seconds=time.monotonic()-t);(R/'ledger.json').write_text(json.dumps(rows,indent=2)+'\n')
print('GATE0',n,a.label,'exit',r.returncode);sys.stdout.buffer.write(r.stdout[-6500:]);sys.stderr.buffer.write(r.stderr[-2500:]);sys.exit(r.returncode)

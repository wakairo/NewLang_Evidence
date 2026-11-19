from meter import run,E
D=E/'build-asan'
run('ASan frontend emit nonzero',[D/'newlangc','--emit-c17-to',E/'nonzero-asan-frontend.c',E/'source/P-nonzero.nl'])
assert (E/'nonzero-asan-frontend.c').read_bytes()==(E/'nonzero.c').read_bytes()
run('ASan API bytes nonzero',[D/'p1529_consumer','agree',E/'source/P-nonzero.nl',E/'nonzero.c'])
for p in sorted((E/'source').glob('N-*.nl')):
    run('final ASan frontend negative '+p.name,[D/'newlangc','--check',p],expect=3)
for variant in ['zero','nonzero']:
    for site,name in [(4,'receiver_text'),(5,'trailing_copy_replay')]:
        run('new composed path ASan OOM '+variant+' '+name,[D/'p1517_safety','oom',E/f'source/P-{variant}.nl',str(site)],selected=2,host=2,sites=[name])

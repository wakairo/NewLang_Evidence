from pathlib import Path
import hashlib,json
R=Path('/workspace/NewLang_P1529'); E=Path('/workspace/p1529-evidence')
T=R/'tests/p1529'; T.mkdir(exist_ok=True)
base=(R/'tests/p1517/P-zero.nl').read_text()
base=base.replace('// P1515 C1150 FIRST: two original H resources, terminal receiver, same T.','// P1529 C1202 own FIRST: finite two-H/four-step terminal consumer composition.')
for a,b in [('Reading','Meter'),('Resource','Cell'),('write_reading','set_count'),('retire','close_cell'),('reading','meter'),('value:','count:'),('route:','kind:'),('@value','@count'),('@route','@kind'),('u8(91)','u8(83)'),('u8(23)','u8(27)'),('u8(67)','u8(83)')]: base=base.replace(a,b)
for name,reads,old,sample,explicit in [('A-prefix-zero',1,0,0,0),('B-prefix-nonzero',1,0,37,0),('C-oldcopy-zero',0,1,0,0),('D-combined-nonzero',1,1,37,1)]:
    s=base
    if reads: s=s.replace('    match try_allocate_one<Cell>() {','    let observed_current = meter@count;\n    let observed_sibling = meter@kind;\n    match try_allocate_one<Cell>() {',1)
    if old: s=s.replace('payload: u8(83)', 'payload: before_start',1)
    s=s.replace('payload: u8(0)',f'payload: u8({sample})')
    if explicit: s=s.replace('    old\n}', '    return old;\n}',1)
    (T/(name+'.nl')).write_text(s)
probe=(R/'tests/p1517/public_owned.c').read_text().replace('91','83').replace('23','27')
probe=probe.replace('P1515 C1150','P1529 C1202').replace('P1517','P1529')
(T/'public_owned.c').write_text(probe)
observer=(R/'tests/p1517/passive-v2.h').read_text().replace('91u','83u').replace('23u','27u').replace('67u','83u')
observer=observer.replace('REQUIRE(calls == 1 && old_copies++ == 0 && x == initial());', 'REQUIRE(calls == 1 && old_copies < (P1529_PREFIX_READS ? 3u : 1u)); \\\n+                REQUIRE(x == (old_copies == 0 ? initial() : old_copies == 1 ? 0u : other())); \\\n+                ++old_copies;')
observer=observer.replace('old_copies == 1 && final_copies == 3','old_copies == (P1529_PREFIX_READS ? 3u : 1u) && final_copies == 3')
(T/'passive.h').write_text(observer)
(T/'CMakeLists.txt').write_text('add_executable(p1529_public_owned tests/p1529/public_owned.c)\ntarget_link_libraries(p1529_public_owned PRIVATE newlang_semantic newlang_parser)\n')
cm=(R/'CMakeLists.txt').read_text(); cm=cm.replace('    include(tests/p1517/CMakeLists.txt)','    include(tests/p1517/CMakeLists.txt)\n    include(tests/p1529/CMakeLists.txt)'); (R/'CMakeLists.txt').write_text(cm)
manifest=[]
for p in sorted(T.iterdir()):
    b=p.read_bytes(); manifest.append(dict(path=str(p.relative_to(R)),bytes=len(b),sha256=hashlib.sha256(b).hexdigest()))
(E/'FIRST-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')

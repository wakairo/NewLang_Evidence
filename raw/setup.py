import hashlib,json,shutil
from pathlib import Path
W=Path('/workspace/NewLang_P1535'); E=Path('/workspace/p1535-evidence'); T=W/'tests/p1535'
T.mkdir(exist_ok=True)
for name in ['P-zero.nl','P-nonzero.nl','N-foreign-domain.nl','N-live-read-at-end.nl','N-post-end-read.nl']:
    shutil.copyfile(Path('/workspace/p1528-gate0/source')/name,T/name)
s=(W/'tests/p1529/D-combined-nonzero.nl').read_text()
s=s.replace('// P1529 C1202 own FIRST: finite two-H/four-step terminal consumer composition.', '// P1535 own FIRST: same-D discarded root read with direct prefix/old Copy composition.')
s=s.replace('fn close_cell(p: ptr<Cell>, a: Allocation, d: LifetimeDomain) -> unit {','fn close_cell(p: ptr<Cell>, a: Allocation, d: LifetimeDomain) -> unit {\n    loan_read(d) { |inspect|\n        let scoped = ref_from_ptr(read, p, inspect);\n        unit\n    };')
(T/'P-composed.nl').write_text(s)
s=(T/'P-zero.nl').read_text()
for name,a,b in [('N-foreign-allocation.nl','retire(p1, a1, d1);','retire(p1, a0, d1);'),('N-foreign-pointer.nl','retire(p1, a1, d1);','retire(p0, a1, d1);')]:
    assert s.count(a)==1
    (T/name).write_text(s.replace(a,b))
s=Path('/workspace/p1528-gate0/public_owned.c').read_text()
s=s.replace('size_t sample, copies, owners, reads, matches, loans;', 'size_t sample, initial, sibling, copies, owners, reads, matches, loans;')
s=s.replace('t->copies ? 0 : 91','t->copies ? 0 : t->initial').replace('sibling.current_value, 23','sibling.current_value, t->sibling')
s=s.replace('static int run(const char *path, size_t sample)','static int run(const char *path, size_t sample, size_t initial, size_t sibling)')
s=s.replace('Trace t = {.sample = sample};','Trace t = {.sample = sample, .initial = initial, .sibling = sibling};')
s=s.replace('if (argc != 3)','if (argc != 3 && argc != 5)')
s=s.replace('return run(argv[1], (size_t)strtoul(argv[2], NULL, 10)) ? 0 : 1;', 'return run(argv[1], (size_t)strtoul(argv[2], NULL, 10),\n               argc == 5 ? (size_t)strtoul(argv[3], NULL, 10) : 91,\n               argc == 5 ? (size_t)strtoul(argv[4], NULL, 10) : 23) ? 0 : 1;')
(T/'public_owned.c').write_text(s)
s=(W/'tests/p1517/passive-v2.h').read_text()
s=s.replace('#ifndef P1517_INDEX', '#ifndef P1535_INITIAL\n#define P1535_INITIAL 91u\n#endif\n#ifndef P1535_SIBLING\n#define P1535_SIBLING 23u\n#endif\n#ifndef P1535_FIRST_BYTE\n#define P1535_FIRST_BYTE 67u\n#endif\n#ifndef P1535_PREFIX_READS\n#define P1535_PREFIX_READS 0u\n#endif\n#ifndef P1535_HAS_READ\n#define P1535_HAS_READ 1u\n#endif\n#ifndef P1517_INDEX',1)
s=s.replace('static bool in_receiver;', 'static bool in_receiver;\nstatic size_t prefix_reads, receiver_roots;')
s=s.replace('return 91u;','return P1535_INITIAL;').replace('return 23u;','return P1535_SIBLING;')
s=s.replace('REQUIRE(calls == 1 && old_copies++ == 0 && x == initial());', 'REQUIRE(calls == 1);                                         \\\n+                if (!old_copies) {                                            \\\n+                    REQUIRE(x == initial());                                  \\\n+                    ++old_copies;                                             \\\n+                } else {                                                      \\\n+                    REQUIRE(prefix_reads < P1535_PREFIX_READS);                \\\n+                    REQUIRE(x == (prefix_reads ? other() : 0u));               \\\n+                    ++prefix_reads;                                           \\\n+                }')
s=s.replace('payload() : 67u','payload() : P1535_FIRST_BYTE')
s=s.replace('++roots;', 'if (in_receiver) {                                                     \\\n+            REQUIRE(P1535_HAS_READ && !receiver_roots++ && payloads == 1);      \\\n+        }                                                                     \\\n+        ++roots;',1)
s=s.replace('REQUIRE(i == 1 && !ended[i] && !(write) && (nominal)', 'REQUIRE(!in_receiver && i == 1 && !ended[i] && !(write) && (nominal)')
s=s.replace('REQUIRE(old_copies == 1 && final_copies == 3 &&', 'REQUIRE(old_copies == 1 && prefix_reads == P1535_PREFIX_READS &&          \\\n+                final_copies == 3 &&')
s=s.replace('REQUIRE(roots == (n == 2 ? 1u : 0u) && payloads == roots);', 'REQUIRE(roots == (n == 2 ? 1u + P1535_HAS_READ : 0u) &&                 \\\n+                receiver_roots == (n == 2 ? P1535_HAS_READ : 0u) &&           \\\n+                payloads == (n == 2 ? 1u : 0u));')
s=s.replace('P1517 H%u physical', 'P1535 H%u physical')
(T/'passive.h').write_text(s)
paths=[*sorted(T.iterdir()),W/'tests/p1517/guest_wrap.c',W/'tests/p1517/safety.c',W/'tests/p1529/consumer.c',W/'tests/p1531/N-live-prefix.nl',W/'tests/p1517/P-zero.nl',W/'tests/p1517/P-nonzero.nl',W/'tests/p1481/Z-success-zero.nl']
manifest=[dict(path=str(p.relative_to(W)),bytes=p.stat().st_size,sha256=hashlib.sha256(p.read_bytes()).hexdigest()) for p in paths]
(E/'FIRST-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print(json.dumps(manifest,indent=2))

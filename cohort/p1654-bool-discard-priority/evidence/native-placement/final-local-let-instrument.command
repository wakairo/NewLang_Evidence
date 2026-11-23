cd -- /workspace/p1544-6afecbd5/p1654-bool-discard-priority
python3 -B -c import\ runpy\,\ sys\;\ from\ pathlib\ import\ Path\;\ source=Path\(sys.argv\[1\]\)\;\ sys.stdout.buffer.write\(runpy.run_path\(\"repo/tests/p1654/run.py\"\)\[\"observe\"\]\(source.read_bytes\(\)\,\ source.stem\ ==\ \"discard\"\)\) /workspace/p1544-6afecbd5/p1654-bool-discard-priority/evidence/final-local/let.c 

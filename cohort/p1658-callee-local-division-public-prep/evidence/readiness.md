# P1658 conditional public preparation

The private candidate is ccdd8d16ca65f5593f7c8b955ec85d360828ea3a, tree 2320df8104003475996e173ccf34ed8e9be5423b, sole parent 350d20c7fb781f15d53e599854224aedceba1bc5. The clean checkout, all 2,817 manifest entries, four-path patch and 129/129 in each local configuration were checked against the LOCAL FINAL.

The exact conditional release is https://github.com/wakairo/NewLang_Compiler/issues/1658#issuecomment-7087316444. Observe adoption of #1657 at the recorded head and verify that GitHub main is its merge, with ordered parents [19e14c6b90e38c8d3875966a47a0e443649ab800, 350d20c7fb781f15d53e599854224aedceba1bc5] and tree 8710553227f620ee5fe65423abac0f28f8c9737b. Check current own and predecessor C instructions for STOP. The public ACTUAL belongs after that gate.

draft-prepared.md holds the draft PR description. prepare-exact.sh takes the individually verified adopted main SHA, creates a separate checkout, applies the exact private commit, and compares parent, tree and full-index patch. run-cohort.sh is prepared for the new exact public candidate before any publication.

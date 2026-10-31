/* FUN_80039d6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039d6c  body 0x80039d6c..0x80039da3  size 59 B
 * body sha256 9b64717b344992f25a36a7010c38ca9a3fb1f75b0ce79c99e6ee665f1d2852e1
 * provider record sha256 d489c9824d44b33f4d792577a8affd922d70c298d0605f3fa87162cc627af7bc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039d6c(void)

{
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    FUN_80039ba8();
  }
  else {
    *(char *)(DAT_800ebb94 + 3) = *(char *)(DAT_800ebb94 + 3) + -1;
  }
  return;
}

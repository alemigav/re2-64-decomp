/* FUN_80039d6c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039d6c  body 0x80039d6c..0x80039da3  size 59 B
 * sha256  fcaf687acdc31f8c6eb723aee9f65e2e7073697b334392dc34770ff49ccdbf80
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

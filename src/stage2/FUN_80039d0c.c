/* FUN_80039d0c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039d0c  body 0x80039d0c..0x80039d6b  size 99 B
 * body sha256 56450b74ab0806d41ab737fecf0ec6d04942414221b2f8d5ff4b838b0df6c95c
 * provider record sha256 11090e111946511180843b11068d0997f477cf1705a64bdb68c383ebb4142abb
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039d0c(void)

{
  if (*(char *)(DAT_800ebb94 + 3) == '\0') {
    *(char *)(DAT_800ebb94 + 0x1f) = *(char *)(DAT_800ebb94 + 0x1f) + *(char *)(DAT_800ebb94 + 0xb);
    FUN_80039aa0(DAT_800ebb94,
                 *(int *)(DAT_800ebb94 + 0x78) + (uint)*(byte *)(DAT_800ebb94 + 0x1f) * 0x18);
  }
  else {
    *(char *)(DAT_800ebb94 + 3) = *(char *)(DAT_800ebb94 + 3) + -1;
  }
  return;
}

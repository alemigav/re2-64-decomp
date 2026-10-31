/* FUN_800ab76c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab76c  body 0x800ab76c..0x800ab7a7  size 63 B
 * body sha256 6a23152dd82f9dd04f46a06e570cb865dcd942c27a8757af5c93fd8622bd31d6
 * provider record sha256 fa8686f1849bba100c1a2d8351ad2ff11f770286d8d2c17d7c009a1ce31277ea
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab76c(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5358();
    FUN_800aaf84();
    DAT_80136310 = '\0';
  }
  return;
}

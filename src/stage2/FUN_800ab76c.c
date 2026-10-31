/* FUN_800ab76c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab76c  body 0x800ab76c..0x800ab7a7  size 63 B
 * sha256  0c7b88b74cf03410ab52d1882f8732a4b79c498fd2ff460231cae6e66b97f236
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

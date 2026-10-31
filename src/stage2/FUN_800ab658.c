/* FUN_800ab658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab658  body 0x800ab658..0x800ab693  size 63 B
 * sha256  1eb8c96cfca33f8ef26014ba709076ec932d24897bc52fbdbff85fabfb2968a8
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800ab658(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5180();
    FUN_800aaf84();
    DAT_80136310 = '\0';
  }
  return;
}

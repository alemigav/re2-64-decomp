/* FUN_800ab658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab658  body 0x800ab658..0x800ab693  size 63 B
 * body sha256 422099778ca090dd1ffaad45ee503c64ff13238b6712bd48d35933e0b8282ca5
 * provider record sha256 c8b8beb723fa2a1724094c666388f252290ce51c296966afcece65fed4ed6330
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

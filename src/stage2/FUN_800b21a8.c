/* FUN_800b21a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b21a8  body 0x800b21a8..0x800b21ef  size 75 B
 * body sha256 d933aa35bfffec678cf2c2f08a71e9bd4b73b11cad42fa41b9419ee3928ba856
 * provider record sha256 a5e397d229f25ebd2560370592f7d014f97a080b99ccb182eb0ac8832c6e5b61
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b21a8(void)

{
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    FUN_800a2444();
    FUN_800aaea8();
    FUN_800aefb4(0);
    FUN_800a56c0();
  }
  return;
}

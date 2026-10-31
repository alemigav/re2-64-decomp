/* FUN_8006d2c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d2c8  body 0x8006d2c8..0x8006d333  size 111 B
 * sha256  6deec2d65ad473c1df312865e7810d7516999d4d598d2e02679e2dbf2efea258
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8006d2c8(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_800e18f8;
  iVar1 = 0x20;
  DAT_800dfb50 = 0;
  DAT_800dfb54 = 0;
  do {
    *puVar3 = 0;
    *(undefined1 *)((int)puVar3 + 0x1e1) = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 0xda;
  } while (iVar1 != 0);
  for (uVar2 = (uint)*(byte *)(DAT_800df92c + 2); uVar2 != 0; uVar2 = uVar2 - 1) {
  }
  return;
}

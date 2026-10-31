/* FUN_8006d2c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006d2c8  body 0x8006d2c8..0x8006d333  size 111 B
 * body sha256 4e0198671397ca04e0b2c78f8b1ebd0149892985b84e025370faa202e1a837e9
 * provider record sha256 264b76f47db2be820b50b7ec43d23412f63b7fa08f010980a1f06fb761cf38f8
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

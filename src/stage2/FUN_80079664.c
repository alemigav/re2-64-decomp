/* FUN_80079664
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80079664  body 0x80079664..0x800796c3  size 99 B
 * sha256  7cf27b620925c3d0ca00bd33caa7faaccc7f95f5e2338d0c273bc28cd8a0e553
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80079664(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x234);
  *(undefined4 *)(iVar1 + 0x1610) = *(undefined4 *)(iVar1 + 8);
  *(undefined4 *)(iVar1 + 0x1614) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined4 *)(iVar1 + 0x1618) = *(undefined4 *)(iVar1 + 0x10);
  *(undefined4 *)(iVar1 + 0x161c) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x1620) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(iVar1 + 0x1624) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x1628) = *(undefined4 *)(iVar1 + 0x20);
  *(undefined4 *)(iVar1 + 0x162c) = *(undefined4 *)(iVar1 + 0x24);
  FUN_8007aa2c();
  return;
}

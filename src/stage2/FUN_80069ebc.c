/* FUN_80069ebc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069ebc  body 0x80069ebc..0x80069f1b  size 99 B
 * sha256  44d71671e959c455e043086d68b43681467fa1a673aea43b76456d109423bfd7
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80069ebc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)(*(ushort *)(param_4 + 6) >> 1);
  iVar1 = ((int)*(short *)(param_4 + 2) + uVar2) - *(int *)(param_1 + 8);
  iVar1 = FUN_80040bb4(uVar2 * uVar2 - iVar1 * iVar1);
  return (param_2 - uVar2) + iVar1;
}

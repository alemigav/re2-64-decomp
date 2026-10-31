/* FUN_80035c9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035c9c  body 0x80035c9c..0x80035dbb  size 291 B
 * sha256  06b1fd49b1cdaef38f11ae9e1990743d6b1ef9718431ba899019285e8df8e31b
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80035c9c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x234);
  FUN_80040e58(param_1 + 100,param_1 + 0x14);
  iVar3 = iVar1 + 0x38;
  FUN_800424ec(param_1 + 0x14,iVar1 + 8,iVar3);
  iVar2 = iVar1 + 0x1b0;
  FUN_800424ec(iVar3,iVar1 + 0x180,iVar2);
  FUN_800424ec(iVar2,iVar1 + 0x2f8,iVar1 + 0x328);
  FUN_800424ec(iVar2,iVar1 + 0x760,iVar1 + 0x790);
  FUN_800424ec(iVar3,iVar1 + 0xd40,iVar1 + 0xd70);
  FUN_800424ec(iVar3,iVar1 + 0x11a8,iVar1 + 0x11d8);
  FUN_80036290(param_1,iVar1,&DAT_800eb414);
  FUN_80036290(param_1,iVar1,&DAT_800eb4a8);
  FUN_80036290(param_1,iVar1,&DAT_800eb53c);
  FUN_80036290(param_1,iVar1,&DAT_800eb604);
  FUN_80036290(param_1,iVar1,&DAT_800eb684);
  FUN_80036694(param_1);
  return;
}

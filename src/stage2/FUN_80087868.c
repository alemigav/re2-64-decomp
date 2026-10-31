/* FUN_80087868
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80087868  body 0x80087868..0x800878fb  size 151 B
 * sha256  173c7b855a37d240ab7c4776938465eb59887b4e8b28cdd68fe93aee13280ba4
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80087868(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = 0;
  iVar6 = *(int *)(*(int *)(param_1 + 0x4c) + 4);
  piVar4 = *(int **)(*(int *)(param_1 + 0x4c) + 8);
  iVar5 = 0;
  if (param_2 < 0) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = (uint)*(ushort *)(&DAT_801275c0 + param_2 * 2);
  }
  while (iVar6 = iVar6 + -1, iVar6 != -1) {
    iVar3 = piVar4[1];
    iVar2 = *piVar4;
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      iVar1 = *(int *)(iVar3 + 8);
      if ((int)uVar7 <= *(int *)(iVar1 + 8)) {
        iVar5 = iVar5 + 1;
        *(undefined4 *)(iVar1 + 8) = 0xffffffff;
      }
      if (iVar8 < *(int *)(iVar1 + 8)) {
        iVar8 = *(int *)(iVar1 + 8);
      }
      iVar3 = iVar3 + 0x10;
    }
    piVar4 = piVar4 + 4;
  }
  return iVar5;
}

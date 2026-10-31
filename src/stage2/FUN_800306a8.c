/* FUN_800306a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800306a8  body 0x800306a8..0x800307c7  size 291 B
 * sha256  b7743d606f4b148a4652a94a8b1fd1911e4389ba405d4a78098bdc47ce49a179
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800306a8(undefined4 param_1,int *param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = param_2[2];
  iVar6 = param_2[6] * iVar7;
  iVar2 = param_2[4];
  iVar5 = 0;
  if (0 < iVar2) {
    do {
      iVar3 = iVar2 - iVar5;
      if (param_2[5] < iVar2 - iVar5) {
        iVar3 = param_2[5];
      }
      iVar2 = param_2[1] - (param_2[6] + iVar5);
      if (iVar3 < iVar2) {
        iVar2 = iVar3;
      }
      iVar3 = iVar2 * iVar7;
      if (iVar2 < 1) {
        return;
      }
      if (param_3 == 0) {
        uVar4 = *(undefined4 *)(iVar5 * 4 + *param_2);
        pcVar1 = (code *)param_2[10];
      }
      else {
        uVar4 = *(undefined4 *)(iVar5 * 4 + *param_2);
        pcVar1 = (code *)param_2[0xb];
      }
      (*pcVar1)(param_1,param_2 + 10,uVar4,iVar6,iVar3);
      iVar2 = param_2[4];
      iVar5 = iVar5 + param_2[5];
      iVar6 = iVar6 + iVar3;
    } while (iVar5 < iVar2);
  }
  return;
}

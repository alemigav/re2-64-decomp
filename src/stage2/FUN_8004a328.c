/* FUN_8004a328
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004a328  body 0x8004a328..0x8004a3df  size 187 B
 * sha256  e00de03536700be6a386b47ab2026fcb1933db86255e79efc241695edd0d7bc0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_8004a328(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  param_2 = param_2 & 0x7f;
  uVar5 = *(int *)(param_3 + param_2 * -8 + 8) - (int)DAT_800e10f2;
  uVar4 = *(int *)(param_1 + param_2 * -8 + 0xc) - (int)DAT_800e10f2;
  if ((int)(uVar5 ^ uVar4) < 0) {
    return false;
  }
  iVar3 = *(int *)(param_2 * 8 + param_1 + 4);
  iVar1 = (*(int *)(param_2 * 8 + param_3) - iVar3) * uVar4;
  iVar2 = uVar5 + uVar4;
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  return (uint)((iVar1 / iVar2 + iVar3) - (int)DAT_800e10f6) <
         (uint)((int)DAT_800e10f4 - (int)DAT_800e10f6);
}

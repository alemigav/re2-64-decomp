/* FUN_80081d1c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081d1c  body 0x80081d1c..0x80081de7  size 207 B
 * sha256  e89915c0df875b3ddb0ef0c43191984deb68babe222a0185da14921ecdf29f98
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80081d1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_80032e74(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                       0x15e);
  uVar2 = 1;
  if (iVar1 != 0) {
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                 (int)*(short *)(param_1 + 0x270));
    if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
      FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
      DAT_800e112a = DAT_800e112a | 2;
    }
    FUN_80089d54(param_1,param_2,param_3,0x200);
    uVar2 = 0;
  }
  return uVar2;
}

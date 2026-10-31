/* FUN_80028780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028780  body 0x80028780..0x800288bf  size 323 B
 * body sha256 a360f7fa13c2d8769e4ae34cd919050c2aec92d9b4b38ab2f93ab6e3541ba9d3
 * provider record sha256 d1fd41f567f766ff9fdd117ea9fc75a2f2bf7dd6ddc2408f8741617b5f2f178d
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80028780(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[4] == 200) {
    (**(code **)(*param_1 + 0x10))();
    (**(code **)param_1[0x5d])(param_1);
    (**(code **)(param_1[5] + 8))(param_1);
    param_1[4] = 0xc9;
  }
  else if (param_1[4] != 0xc9) {
    *(undefined4 *)(*param_1 + 0x14) = 0xe;
    *(int *)(*param_1 + 0x18) = param_1[4];
    (**(code **)*param_1)(param_1);
  }
  iVar1 = (**(code **)(param_1[0x5d] + 4))(param_1);
  if (iVar1 == 1) {
    if (*(int *)(param_1[0x5d] + 0x54) != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x33;
      (**(code **)*param_1)(param_1);
    }
    if (param_2 != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x2b;
      (**(code **)*param_1)(param_1);
    }
    iVar2 = 200;
  }
  else {
    if (1 < iVar1) {
      return iVar1;
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    FUN_8002857c(param_1);
    iVar2 = 0xca;
  }
  param_1[4] = iVar2;
  return iVar1;
}

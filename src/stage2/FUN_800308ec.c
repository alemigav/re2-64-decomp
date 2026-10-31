/* FUN_800308ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800308ec  body 0x800308ec..0x80030a3b  size 339 B
 * sha256  ac84af7050167db5ad4bca12f907ef11c4ef69090b34e5f9c7f8d6a3349343f1
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
int FUN_800308ec(int *param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  
  if (((uint)param_2[1] <= param_3) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xf;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[6] + param_2[4]) < param_3 + param_2[3])) {
    if (param_2[8] == 0) {
      *(undefined4 *)(*param_1 + 0x14) = 0x3d;
      (**(code **)*param_1)(param_1);
    }
    if (param_2[7] != 0) {
      FUN_800306a8(param_1,param_2,1);
      param_2[7] = 0;
    }
    if ((uint)param_2[6] < param_3) {
      param_2[6] = param_3;
    }
    else {
      iVar1 = (param_3 + param_2[3]) - param_2[4];
      if (iVar1 < 0) {
        iVar1 = 0;
      }
      param_2[6] = iVar1;
    }
    if (param_4 == 0) {
      FUN_800306a8(param_1,param_2,0);
      goto LAB_80030a00;
    }
  }
  else {
LAB_80030a00:
    if (param_4 == 0) goto LAB_80030a0c;
  }
  param_2[7] = 1;
LAB_80030a0c:
  return *param_2 + (param_3 - param_2[6]) * 4;
}

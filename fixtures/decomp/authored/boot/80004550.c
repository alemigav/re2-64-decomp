typedef unsigned int undefined4;












int inflate_init(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  FUN_800013b0(param_2);
  uVar1 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar1;
  return param_1;
}

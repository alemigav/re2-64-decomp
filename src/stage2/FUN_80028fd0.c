/* FUN_80028fd0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028fd0  body 0x80028fd0..0x8002904b  size 127 B
 * sha256  c584c7dcc210fc10a0f19c1914240de75e79c1d07cc488aa7677ff30948af6e2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80028fd0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x5b];
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  if (param_2 == 0) {
    if (*(int *)(iVar1 + 0x38) != 0) {
      *(undefined4 *)(*param_1 + 0x14) = 4;
      (**(code **)*param_1)();
    }
    *(code **)(iVar1 + 4) = FUN_8002904c;
  }
  else {
    *(undefined4 *)(*param_1 + 0x14) = 4;
    (**(code **)*param_1)();
  }
  return;
}

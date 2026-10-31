/* FUN_80001510
 * image   boot (boot), base 0x80000480
 * address 0x80001510  body 0x80001510..0x800015df  size 211 B
 * sha256  707d1abc84696b3b7e2e90d9d3b8526c3ec9dd78c7143a436642e6ef3438eceb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80001510(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if (param_1[0xd] != 0) {
    *param_3 = param_1[0xe];
  }
  if (*param_1 - 4U < 2) {
    (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1[3]);
  }
  if (*param_1 == 6) {
    FUN_80002b8c(param_1[3],param_2);
    FUN_800042f4(param_1[2],param_2);
    FUN_800042f4(param_1[1],param_2);
  }
  *param_1 = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = param_1[9];
  param_1[0xb] = param_1[9];
  if ((code *)param_1[0xd] != (code *)0x0) {
    iVar1 = (*(code *)param_1[0xd])(0,0,0);
    param_1[0xe] = iVar1;
    *(int *)(param_2 + 0x30) = iVar1;
  }
  return;
}

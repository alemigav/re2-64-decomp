/* FUN_8002e6fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e6fc  body 0x8002e6fc..0x8002e7bf  size 199 B
 * sha256  7cef64204d240a3d7f41669355aeccfb7a1985c65571d41d5f6f90120768329e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002e6fc(int *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x1c);
  param_1[0x5c] = (int)puVar1;
  *puVar1 = FUN_8002e5d0;
  puVar1[2] = 0;
  if (param_1[0x11] != 0) {
    puVar1[4] = param_1[0x42];
    if (param_2 == 0) {
      uVar2 = (**(code **)(param_1[1] + 8))(param_1,1,param_1[0x17] * param_1[0x19]);
      puVar1[3] = uVar2;
    }
    else {
      *(undefined4 *)(*param_1 + 0x14) = 4;
      (**(code **)*param_1)(param_1);
    }
  }
  return;
}

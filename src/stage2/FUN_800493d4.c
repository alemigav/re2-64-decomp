/* FUN_800493d4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800493d4  body 0x800493d4..0x8004944b  size 123 B
 * sha256  621243b9988464630d97c82c0c24e3041a715a851cb62c2c9e3ad008178d30eb
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800493d4(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  
  fVar1 = (float)func_0x8000d050(param_2);
  uVar2 = func_0x80006be0(param_2);
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 0x3f800000;
  param_1[4] = uVar2;
  param_1[5] = fVar1;
  param_1[6] = 0;
  param_1[7] = -fVar1;
  param_1[8] = uVar2;
  return;
}

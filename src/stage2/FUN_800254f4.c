/* FUN_800254f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800254f4  body 0x800254f4..0x80025573  size 131 B
 * sha256  f76cac8da5c82adab0f1ed100da5576f276eca92149aa67851649f8ac824735e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800254f4(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_800c56f0 = param_1;
  *param_1 = 1;
  param_1[3] = 0xd0;
  param_1[5] = 0x1000;
  param_1[7] = 0x800;
  param_1[8] = &DAT_800c52e0;
  param_1[2] = entry;
  param_1[9] = 0x400;
  uVar2 = DAT_800c56e4;
  uVar1 = DAT_800c4ea0;
  param_1[0xc] = &DAT_800c6058;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[10] = uVar1;
  param_1[0xb] = uVar2;
  return;
}

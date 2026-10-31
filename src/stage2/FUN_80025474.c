/* FUN_80025474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80025474  body 0x80025474..0x800254f3  size 131 B
 * sha256  5bb5a7fabca1289c30e3060cb31d3ff3bda20275db96b667c805934c96eac28d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80025474(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  DAT_800c56ec = param_1;
  *param_1 = 1;
  param_1[3] = 0xd0;
  param_1[5] = 0x1000;
  param_1[7] = 0x800;
  param_1[8] = &DAT_800c52e0;
  param_1[2] = entry;
  param_1[9] = 0x400;
  uVar2 = DAT_800c56e4;
  uVar1 = DAT_800c4ea0;
  param_1[0xc] = &DAT_800c56f8;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[10] = uVar1;
  param_1[0xb] = uVar2;
  return;
}

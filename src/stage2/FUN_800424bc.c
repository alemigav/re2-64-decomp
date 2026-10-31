/* FUN_800424bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800424bc  body 0x800424bc..0x800424eb  size 51 B
 * sha256  3fbdcadf1d823e6f7b44376b77a4a7495b2bdf0ae9e05c25cd4455ff11cb1feb
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_800424bc(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  return param_2;
}

/* FUN_80046ec4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80046ec4  body 0x80046ec4..0x80046f97  size 215 B
 * sha256  12cb00fbe86297fd79519475ded248ad14bef5b0def4dd626b9dcc62febf0171
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80046ec4(undefined4 *param_1)

{
  func_0x80009170(0x80139aa0);
  param_1[1] = &DAT_800efdf0;
  *param_1 = 0xde000000;
  param_1[2] = 0xe200001c;
  param_1[3] = 0x5049d8;
  param_1[4] = 0xfa000000;
  param_1[5] = 0xffffff00;
  param_1[7] = 0xfffff3f9;
  param_1[6] = 0xfc11fe23;
  param_1[8] = 0xde000000;
  param_1[9] = &DAT_800efe68;
  DAT_800effa0 = 100;
  param_1[10] = 0xd9c0f9fa;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}

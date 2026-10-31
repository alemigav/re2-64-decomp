/* FUN_80042454
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80042454  body 0x80042454..0x8004249b  size 75 B
 * sha256  9c5bb87a95c46d6342292fcd779a775280b24f5e8a10ccd41a35e9ff1fbcd465
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80042454(undefined4 *param_1,undefined4 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  param_2[4] = param_1[4];
  param_2[5] = param_1[5];
  param_2[6] = param_1[6];
  param_2[7] = param_1[7];
  return param_2;
}

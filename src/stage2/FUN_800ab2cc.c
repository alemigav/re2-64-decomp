/* FUN_800ab2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab2cc  body 0x800ab2cc..0x800ab32f  size 100 B
 * body sha256 ede429a3d026e343cec980c716567f68b49b9e6bc56cd3e0482ebbe0ca8ebeb5
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800ab2cc.c
 * extents and pins: fixtures/decomp/recovered.json
 */












void FUN_800ab2cc(float *param_1,float *param_2,float *param_3)

{
  *param_1 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
  param_1[1] = param_2[2] * *param_3 - *param_2 * param_3[2];
  param_1[2] = *param_2 * param_3[1] - param_2[1] * *param_3;
  return;
}

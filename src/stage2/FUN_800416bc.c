/* FUN_800416bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800416bc  body 0x800416bc..0x80041707  size 76 B
 * body sha256 a01a8bcfb797cc1fcb0649695545a809060d437d839ea774bb662780042094e1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800416bc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












void FUN_800416bc(undefined2 *param_1,undefined2 *param_2)

{
  *param_2 = *param_1;
  param_2[1] = param_1[3];
  param_2[2] = param_1[6];
  param_2[3] = param_1[1];
  param_2[4] = param_1[4];
  param_2[5] = param_1[7];
  param_2[6] = param_1[2];
  param_2[7] = param_1[5];
  param_2[8] = param_1[8];
  return;
}

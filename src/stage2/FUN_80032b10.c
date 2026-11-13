/* FUN_80032b10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032b10  body 0x80032b10..0x80032b5b  size 76 B
 * body sha256 98d26b31f0d90541411bcce2e515edd139f51aeb7bd45eba08b229d4ecfdff5d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80032b10.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












undefined4 FUN_80032b10(int *param_1,short *param_2)

{
  if (((uint)(int)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(int)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}

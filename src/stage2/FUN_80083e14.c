/* FUN_80083e14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e14  body 0x80083e14..0x80083e5f  size 76 B
 * body sha256 8ce521f4c42291c1dd3ec651558f0166f8623ee545b860e84bfdd4e6ef738f92
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80083e14.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;












undefined4 FUN_80083e14(int *param_1,short *param_2)

{
  if (((uint)(ushort)param_2[2] < (uint)(*param_1 - (int)*param_2)) ||
     ((uint)(ushort)param_2[3] < (uint)(param_1[2] - (int)param_2[1]))) {
    return 0;
  }
  return 1;
}

/* FUN_80073f28
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073f28  body 0x80073f28..0x80073f63  size 60 B
 * body sha256 51fa203f3a6e0f2abb015b7a17b0966f15762c96da80e1b1e0405b32f4d3ae4c
 * recovered byte-exact (read from the words (M448): the image masks the SECOND argument to 16 bits (`andi a1,a1,-1`) after the add, so the parameter is an `unsigned short` and the draft's `param_1[1] + 0x300` passes a full word. The draft already carried `(uint)(ushort)` on the fourth argument; the second was missing the same truncation.)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80073f28.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;
typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef unsigned int uint;












undefined4 FUN_80073f28(undefined2 *param_1)

{
  FUN_8004ac04(0,(ushort)(param_1[1] + 0x300),*param_1,(uint)(ushort)param_1[2] << 0x10);
  return 0;
}

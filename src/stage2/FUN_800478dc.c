/* FUN_800478dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478dc  body 0x800478dc..0x80047913  size 56 B
 * body sha256 a4b89cf3a5bd126b40747311c23d1383398bf1d8fc81a0ecf1bfabe8addb7b68
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800478dc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short undefined2;












void FUN_800478dc(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
                 undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8,
                 undefined2 param_9)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  *(undefined2 *)(param_1 + 0xc) = param_4;
  *(undefined2 *)(param_1 + 0xe) = param_5;
  *(undefined2 *)(param_1 + 0x14) = param_6;
  *(undefined2 *)(param_1 + 0x16) = param_7;
  *(undefined2 *)(param_1 + 0x1c) = param_8;
  *(undefined2 *)(param_1 + 0x1e) = param_9;
  return;
}

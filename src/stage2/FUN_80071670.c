/* FUN_80071670
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071670  body 0x80071670..0x800716af  size 64 B
 * body sha256 644b13c6a06bd846826cb76818846ee1d08b198b660d426dda7d88eca4603dd8
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80071670.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












undefined4 FUN_80071670(int param_1)

{
  FUN_80038f40(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
  return 1;
}

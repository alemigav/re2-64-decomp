/* FUN_8006eae0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006eae0  body 0x8006eae0..0x8006eb07  size 40 B
 * body sha256 3c3a972717e2933f755ae9d888dbd9fee7a5258aeac7eabc017e923df0648be1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006eae0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;












undefined4 FUN_8006eae0(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  FUN_8006d284();
  return 1;
}

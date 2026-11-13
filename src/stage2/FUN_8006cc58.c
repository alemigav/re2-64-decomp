/* FUN_8006cc58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006cc58  body 0x8006cc58..0x8006cccb  size 116 B
 * body sha256 3f46bc7da792788996595c4ff94ffee9964f535e0e96d791288391cd7daba208
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006cc58.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_8006cc58(int param_1,int param_2)

{
  *(int *)(param_1 + 0x1c) =
       ((int)((*(uint *)(param_1 + 0x1c) >> 0x10) + param_2) % 0xffff) * 0x10000 |
       (int)((*(uint *)(param_1 + 0x1c) & 0xffff) + param_2) % 0xffff;
  return;
}

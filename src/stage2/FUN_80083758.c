/* FUN_80083758
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083758  body 0x80083758..0x8008377f  size 40 B
 * body sha256 5199bacff0d32b751e7698eb5c1bdda37c65d12b7b28645125b703988d31e017
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80083758.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_80083758(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 | 0x80000000U >> (param_2 & 0x1f);
  return;
}

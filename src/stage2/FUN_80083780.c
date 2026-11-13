/* FUN_80083780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083780  body 0x80083780..0x800837ab  size 44 B
 * body sha256 9808bab8260ced2c93c5baa55ef6f86a027ec13606fb93b27949e6b020ff3ffe
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80083780.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int uint;












void FUN_80083780(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 & ~(0x80000000U >> (param_2 & 0x1f));
  return;
}

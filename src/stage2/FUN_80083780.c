/* FUN_80083780
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083780  body 0x80083780..0x800837ab  size 47 B
 * sha256  3ef76d624b0284d958123a1675a54c8ea29df7927cf3a6dcc1e8ec627e7ef07e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80083780(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_2 >> 5) * 4 + param_1);
  *puVar1 = *puVar1 & ~(0x80000000U >> (param_2 & 0x1f));
  return;
}

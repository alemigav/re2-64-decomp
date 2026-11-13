/* FUN_80162a8c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162a8c  body 0x80162a8c..0x80162ad3  size 72 B
 * body sha256 b0e61720637df5ba46a2ebed0bc2fab8ae772094b984c997892f05b7667d8161
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b5346/80162a8c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_LAB_8016307c;












void FUN_80162a8c(int param_1)

{
  (*(code *)(&PTR_LAB_8016307c)[*(byte *)(param_1 + 6)])();
  FUN_80162908(param_1);
  return;
}

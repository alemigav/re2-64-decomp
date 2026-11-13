/* FUN_8016345c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016345c  body 0x8016345c..0x8016348f  size 52 B
 * body sha256 9f18c138035c4029ec9654b66d7ed5bdb7aad41ff8a0f610ab80e04b200f43f1
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/8016345c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166704;












void FUN_8016345c(int param_1)

{
  (*(code *)(&PTR_FUN_80166704)[*(byte *)(param_1 + 6)])();
  return;
}

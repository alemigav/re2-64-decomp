/* FUN_80164d84
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80164d84  body 0x80164d84..0x80164db7  size 52 B
 * body sha256 8e7bb45aa4d17068cae0aacd059a934efcf8d678e79d46d596ea88a1cb46dd7c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008900e/80164d84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80168cb4;












void FUN_80164d84(int param_1)

{
  (*(code *)(&PTR_FUN_80168cb4)[*(byte *)(param_1 + 5)])();
  return;
}

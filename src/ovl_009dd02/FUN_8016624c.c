/* FUN_8016624c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016624c  body 0x8016624c..0x8016627f  size 52 B
 * body sha256 b8f44e4d789f3a627c2f3e425a441db37639a711f3789e2adbe9f191b58748ea
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/8016624c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016739c;












void FUN_8016624c(int param_1)

{
  (*(code *)(&PTR_FUN_8016739c)[*(byte *)(param_1 + 5)])();
  return;
}

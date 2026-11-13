/* FUN_80164a78
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164a78  body 0x80164a78..0x80164aab  size 52 B
 * body sha256 a6f62a50acd17187f4dc0a707d84a54a94e96d162f13739fb844910f98b41c02
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80164a78.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167ef0;












void FUN_80164a78(int param_1)

{
  (*(code *)(&PTR_FUN_80167ef0)[*(byte *)(param_1 + 0x2be)])();
  return;
}

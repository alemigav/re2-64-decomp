/* FUN_80162218
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80162218  body 0x80162218..0x8016224b  size 52 B
 * body sha256 648d90dc0277c6a451f486345fed64431e149284c9c603636c646d6e3865b4fa
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80162218.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167dc0;












void FUN_80162218(int param_1)

{
  (*(code *)(&PTR_FUN_80167dc0)[*(byte *)(param_1 + 5)])();
  return;
}

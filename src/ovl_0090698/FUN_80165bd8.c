/* FUN_80165bd8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165bd8  body 0x80165bd8..0x80165c0b  size 52 B
 * body sha256 505f956388730a1c2c78643a8f476f0b4a4b31e7ae772abd2a47e4358c5a4d1d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80165bd8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167fc4;












void FUN_80165bd8(int param_1)

{
  (*(code *)(&PTR_FUN_80167fc4)[*(byte *)(param_1 + 6)])();
  return;
}

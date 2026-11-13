/* FUN_801644e4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801644e4  body 0x801644e4..0x80164517  size 52 B
 * body sha256 5ba1c0014ab54bca5a374186e7f2e63eb7d07a155f8038d1735709fc64ff0f86
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/801644e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167e40;












void FUN_801644e4(int param_1)

{
  (*(code *)(&PTR_FUN_80167e40)[*(byte *)(param_1 + 6)])();
  return;
}

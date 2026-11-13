/* FUN_801646a8
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801646a8  body 0x801646a8..0x801646db  size 52 B
 * body sha256 d84f92171fe26b31e1bc87ef1d21a86d018152c8d72a41ff5c91316fde9c2d8c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008bef8/801646a8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166124;












void FUN_801646a8(int param_1)

{
  (*(code *)(&PTR_FUN_80166124)[*(byte *)(param_1 + 5)])();
  return;
}

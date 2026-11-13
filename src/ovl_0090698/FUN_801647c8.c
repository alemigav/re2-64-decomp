/* FUN_801647c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801647c8  body 0x801647c8..0x801647fb  size 52 B
 * body sha256 0c1159dd3bb7acdf30552d759980c3792240670164d4bc22026c8ee2d4c98fec
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/801647c8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167ed8;












void FUN_801647c8(int param_1)

{
  (*(code *)(&PTR_FUN_80167ed8)[*(byte *)(param_1 + 0x2be)])();
  return;
}

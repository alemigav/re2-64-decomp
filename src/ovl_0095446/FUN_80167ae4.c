/* FUN_80167ae4
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80167ae4  body 0x80167ae4..0x80167b17  size 52 B
 * body sha256 9986b571bf1ba05fa99e77c7c62b986e202f91c1771ae26ee5ac9781be85a34f
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0095446/80167ae4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_801682d8;












void FUN_80167ae4(int param_1)

{
  (**(code **)(&DAT_801682d8 + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}

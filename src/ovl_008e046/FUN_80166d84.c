/* FUN_80166d84
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80166d84  body 0x80166d84..0x80166db7  size 52 B
 * body sha256 011a8c1efaabbfe9415d028c09737e382bcba335788273ead0ca87772c1f2d74
 * recovered byte-exact (imported: closed by the dat:width mechanism pass (12 of 13 -> 13 of 13) (M416))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008e046/80166d84.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef unsigned int uint;
typedef int code();
extern unsigned char DAT_8016752c;












void FUN_80166d84(int param_1)

{
  (**(code **)(&DAT_8016752c + (uint)*(byte *)(param_1 + 5) * 4))();
  return;
}

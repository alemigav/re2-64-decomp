/* FUN_80164d5c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80164d5c  body 0x80164d5c..0x80164d8f  size 52 B
 * body sha256 e704dde01516139cfb182bcd100c9076ab55b0c2430d3aa3b2c7fa559a77e4d3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80164d5c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166e58;












void FUN_80164d5c(int param_1)

{
  (*(code *)(&PTR_FUN_80166e58)[*(byte *)(param_1 + 6)])();
  return;
}

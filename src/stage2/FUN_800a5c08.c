/* FUN_800a5c08
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c08  body 0x800a5c08..0x800a5c33  size 44 B
 * body sha256 e4b6ca283e7f17c5adf47979e1badebec47a91a908d386eeb25efdb46e108117
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5c08.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int _DAT_80143f0c;














undefined4 FUN_800a5c08(int param_1)

{
  return *(undefined4 *)(param_1 * 0x68 + _DAT_80143f0c + 0x14);
}

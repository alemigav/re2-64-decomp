/* FUN_8009b224
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009b224  body 0x8009b224..0x8009b24b  size 40 B
 * body sha256 a6254429353ecfa4cf1fb0d7e486c91850dc5a9c96365f7d5e3b3eaa80e90eeb
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8009b224.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char bool;
extern unsigned int DAT_800e8ce0;












bool FUN_8009b224(void)

{
  int iVar1;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0xc3);
  return iVar1 != 0;
}

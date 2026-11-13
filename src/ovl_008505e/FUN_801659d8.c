/* FUN_801659d8
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801659d8  body 0x801659d8..0x80165a0b  size 52 B
 * body sha256 abfb949c3913eae867cf3fa305f2dacedf864c8435118e8f2fc55243ccd8870d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801659d8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166e8c;












void FUN_801659d8(int param_1)

{
  (*(code *)(&PTR_FUN_80166e8c)[*(byte *)(param_1 + 6)])();
  return;
}

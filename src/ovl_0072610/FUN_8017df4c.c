/* FUN_8017df4c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017df4c  body 0x8017df4c..0x8017df6b  size 32 B
 * body sha256 10310979d2518ebd0b35ad8a66250bedf0645104b73bce73cb81af7497cc3ac7
 * recovered byte-exact (read from the words (M384): 8 of 8, eight words, a wrapper passing a fixed address -- it must be a SYMBOL, not a literal, or the `lui`/`addiu` pair becomes `ori`)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017df4c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 D_80185710[];
extern void FUN_8017b5e8(u8 *p);

void FUN_8017df4c(void)
{
    FUN_8017b5e8((u8 *)D_80185710);
}

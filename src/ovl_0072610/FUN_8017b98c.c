/* FUN_8017b98c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b98c  body 0x8017b98c..0x8017b9bb  size 48 B
 * body sha256 fc77c674253781ea837dcf535a708be705c7df265bc3c2112568d960b6f31cbc
 * recovered byte-exact (read from the words (M370): 12 of 12, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017b98c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 FUN_8017b8f4(void);

u32 FUN_8017b98c(void)
{
    u32 a = FUN_8017b8f4();
    u32 b = FUN_8017b8f4();

    return (a << 8) | b;
}

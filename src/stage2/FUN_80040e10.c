/* FUN_80040e10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040e10  body 0x80040e10..0x80040e2f  size 32 B
 * body sha256 92042f14cd656b181460f2af17e9a3b7a96388e3193f72537b2d74c9ad735701
 * recovered byte-exact (read from the words (M368): 8 of 8, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/80040e10.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern u8 D_800f5e30[];

f32 FUN_80040e10(u32 a0)
{
    u8 *b = D_800f5e30;

    return *(f32 *)(b + (a0 & 0xfff) * 4);
}

/* FUN_800b2618
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b2618  body 0x800b2618..0x800b2637  size 32 B
 * body sha256 ea1023fd9e98eacbc2549f4536fb89cc9f5da05ac4600ef246a755a94084b997
 * recovered byte-exact (read from the words (M368): 8 of 8, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/800b2618.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern u8 D_80147fb0[];

s32 FUN_800b2618(u32 a0)
{
    u8 *b = D_80147fb0;

    return *(s16 *)(b + (a0 & 15) * 2);
}

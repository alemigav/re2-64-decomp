/* FUN_80033160
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033160  body 0x80033160..0x800331b7  size 88 B
 * body sha256 a7e63400b281d396b22bbf504ae9a689cbd79377d60acd1ed32991597d6ada0d
 * recovered byte-exact (read from the words (M382): 22 of 22, twenty-two words, four `lh` arguments into one call, then a signed wrap and a 12-bit modular compare -- `(x + 0x400) & 0xfff < 0x800` is a half-turn test)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80033160.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern s32 FUN_80032d14(s16 a, s16 b, s16 c, s16 d);

s32 FUN_80033160(u8 *a, u8 *b)
{
    s32 d = (s16)FUN_80032d14(*(s16 *)(a + 42), *(s16 *)(a + 50), *(s16 *)(b + 42), *(s16 *)(b + 50));

    return ((*(s16 *)(b + 102) - d + 0x400) & 0xfff) < 0x800;
}

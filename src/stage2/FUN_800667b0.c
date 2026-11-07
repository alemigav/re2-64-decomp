/* FUN_800667b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667b0  body 0x800667b0..0x800667d3  size 36 B
 * body sha256 a6ac9e1a223dd3f3b47f1123d47f78dc1ce280ba1a8d42e9781939a9167c8af4
 * recovered byte-exact (read from the words (M378): 9 of 9, nine words, a four-valued comparison built from two sign bits -- `srl 31` / `srl 30` then two `sllv`s, so the source shifts by the sign, not by a `slt`)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800667b0.c
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

s32 FUN_800667b0(s32 a, s32 b, s32 c, s32 d)
{
    return (1 << ((u32)(a - c) >> 31)) << ((((u32)(b - d)) >> 30) & 2);
}

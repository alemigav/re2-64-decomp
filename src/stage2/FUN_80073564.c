/* FUN_80073564
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073564  body 0x80073564..0x8007358f  size 44 B
 * body sha256 23a7a3d3e8a9c82cc21c8fada4c312a2d2b11af78a79f992b8444d478e7fe98e
 * recovered byte-exact (read from the words (M378): 11 of 11, eleven words, the same shape used for a nonzero test -- `sltu` in the delay slot is the return)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80073564.c
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

extern u8 D_800c76b0[];

s32 FUN_80073564(u8 *ctx)
{
    u8 *t = D_800c76b0;

    *(u32 *)(ctx + 0x1c) += 1;
    return *(u16 *)(t + 0x18000 + 7476) != 0;
}

/* FUN_80071df0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071df0  body 0x80071df0..0x80071e13  size 36 B
 * body sha256 f47e8087929b994b92d1cab018f467dc2ffbb10ae5179bd70a67860a2c9127cc
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, a byte copied through two loaded pointers and a pointer field advanced by two)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80071df0.c
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

s32 FUN_80071df0(u8 *ctx)
{
    u8 *src = *(u8 **)(ctx + 0x1c);
    u8 *dst = *(u8 **)(ctx + 0x154);

    dst[0x1e9] = src[1];
    *(u32 *)(ctx + 0x1c) += 2;
    return 1;
}

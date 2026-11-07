/* FUN_80074024
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074024  body 0x80074024..0x8007404b  size 40 B
 * body sha256 7c6fd5a29b1fe2b3fd2964eb9a47eeeea68a7581ef2ef757dfb535ca040a52b2
 * recovered byte-exact (read from the words (M375): 10 of 10, ten words, the M372 shape again: symbol plus 0x18000 kept apart, then a loaded pointer indexed)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80074024.c
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

s32 FUN_80074024(u16 *p)
{
    u8 *t = D_800c76b0;
    u32 q = *(u32 *)(t + 0x18000 + 648);

    *(u16 *)(q + 424) = *p;
    return 0;
}

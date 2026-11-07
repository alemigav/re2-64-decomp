/* FUN_8006e338
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e338  body 0x8006e338..0x8006e34b  size 20 B
 * body sha256 8ae13d3c9aae6c205a63a627571da5715160b28c4211ac94d8cd9714e63d52b1
 * recovered byte-exact (read from the words (M364): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8006e338.c
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
u32 FUN_8006e338(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 6;

    return 1;
}

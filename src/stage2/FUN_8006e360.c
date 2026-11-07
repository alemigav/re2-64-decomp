/* FUN_8006e360
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e360  body 0x8006e360..0x8006e387  size 40 B
 * body sha256 a8936758cd080fdea9831ed383bd1b84326bfb2a20d6fa79df4b009936dedc84
 * recovered byte-exact (read from the words (M364): 10 of 10, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8006e360.c
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
u32 FUN_8006e360(u8 *a0)
{
    u8 *p = a0 + *(s8 *)(a0 + 2);

    p[8] = p[8] - 1;
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 2;

    return 1;
}

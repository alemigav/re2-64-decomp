/* FUN_8004d320
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d320  body 0x8004d320..0x8004d343  size 36 B
 * body sha256 ff81bf3bc930ef95a497bb68000aa49536426e3e01edb8fd5ca32177c280d9ca
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, a load returned plus an eight-byte zero store -- the pair is what makes gcc materialise two zeros)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004d320.c
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

extern u32 D_8010b700[];

u32 FUN_8004d320(void)
{
    u32 ret = D_8010b700[15];

    *(s64 *)(D_8010b700 + 14) = 0;
    return ret;
}

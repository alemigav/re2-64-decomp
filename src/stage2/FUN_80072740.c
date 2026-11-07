/* FUN_80072740
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072740  body 0x80072740..0x80072753  size 20 B
 * body sha256 6de9a7283637b796072906968de90712b052d00748cab747aa538c94a1e5ba06
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/80072740.c
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
u32 FUN_80072740(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 6;

    return 1;
}

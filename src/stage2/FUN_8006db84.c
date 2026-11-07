/* FUN_8006db84
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db84  body 0x8006db84..0x8006db97  size 20 B
 * body sha256 07b7ddc24de2308c7a8f095cd5de5823187e0190407eb61f9f3ebe2bcbf46909
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006db84.c
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
u32 FUN_8006db84(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 1;

    return 2;
}

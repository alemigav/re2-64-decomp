/* FUN_80072754
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80072754  body 0x80072754..0x80072767  size 20 B
 * body sha256 8f6db801fb8d7952cab668e790c4ede08fe937e705118ff2418975af5eddf868
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80072754.c
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
u32 FUN_80072754(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 1;

    return 1;
}

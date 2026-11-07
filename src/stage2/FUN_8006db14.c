/* FUN_8006db14
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006db14  body 0x8006db14..0x8006db27  size 20 B
 * body sha256 d6927aca41e8b152aafa278d811d59dd19c6520ba278387cfbd1f478860ead8d
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006db14.c
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
u32 FUN_8006db14(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 1;

    return 1;
}

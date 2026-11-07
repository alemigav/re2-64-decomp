/* FUN_8006e34c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e34c  body 0x8006e34c..0x8006e35f  size 20 B
 * body sha256 b0334cc35fc3e37a229d9dbb52086690d9287ad0bd62a7bd0d33554cdb6429d9
 * recovered byte-exact (read from the words (M364): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8006e34c.c
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
u32 FUN_8006e34c(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 2;

    return 1;
}

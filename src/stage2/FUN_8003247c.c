/* FUN_8003247c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003247c  body 0x8003247c..0x800324a7  size 44 B
 * body sha256 0340a288bacee1de8fb643ac2b9ee727e4901d7fea7677a3c4e5c7df06d849f2
 * recovered byte-exact (read from the words (M378): 11 of 11, eleven words, the M372 shape a third time: symbol plus 0x18000 kept apart, then a byte decremented through it)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003247c.c
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

void FUN_8003247c(u32 *p)
{
    u8 *t = D_800c76b0;

    p[0] = 0;
    p[1] = 0;
    *(u8 *)(t + 0x18000 + 6774) -= 1;
}

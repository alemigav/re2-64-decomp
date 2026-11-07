/* FUN_8003bfb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003bfb4  body 0x8003bfb4..0x8003bfc7  size 20 B
 * body sha256 79dd2de2fd4c28f73c3b045e11f1ce474880a013a470b288e5a8146b02a4b5b9
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8003bfb4.c
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
extern u8 *D_800ebb94;

void FUN_8003bfb4(void)
{
    u8 *p = D_800ebb94;

    p[0] = 0;
    *(u16 *)(p + 24) = 0;
}

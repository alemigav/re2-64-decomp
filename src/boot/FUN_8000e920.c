/* FUN_8000e920
 * image   boot (boot), base 0x80000480
 * address 0x8000e920  body 0x8000e920..0x8000e977  size 88 B
 * body sha256 e6aa067f16d778ef161aac72fdc78287615486db21dea1890e03ed39b875ac82
 * recovered byte-exact (read from the words (M382): 22 of 22, twenty-two words, a call whose result becomes the next call's argument, with three stores into a pointer loaded from a global between them)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000e920.c
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

extern u32 D_800129d4;
extern u32 FUN_800072e0(void);
extern void FUN_80007300(u32 v);

void FUN_8000e920(u32 a, u32 b, u16 c)
{
    u8 *p;
    u32 r = FUN_800072e0();

    p = (u8 *)D_800129d4;
    *(u32 *)(p + 16) = a;
    *(u32 *)(p + 20) = b;
    *(u16 *)(p + 2) = c;
    FUN_80007300(r);
}

/* FUN_800390b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800390b8  body 0x800390b8..0x800390df  size 40 B
 * body sha256 74185b9145c716185486fe215137ae5665264942d7f08f9ce04ee905606f95f9
 * recovered byte-exact (read from the words (M375): 10 of 10, ten words, an index of 124 bytes per entry (31 words) built by shift-subtract-shift)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800390b8.c
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

extern u8 D_800ebda8[];

s32 FUN_800390b8(u32 i, u8 v)
{
    u8 *b = D_800ebda8;

    b[(i & 0xffff) * 124] = v;
    return 0;
}

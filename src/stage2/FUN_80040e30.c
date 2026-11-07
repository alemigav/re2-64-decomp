/* FUN_80040e30
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80040e30  body 0x80040e30..0x80040e57  size 40 B
 * body sha256 5a8b9dd52d7a826190ea2997ba2013c421bcdb7f72a91caf1f38090b2d5b7efa
 * recovered byte-exact (read from the words (M375): 10 of 10, ten words, a masked float table read -- `lwc1` is the tell that the accessor returns a float)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80040e30.c
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

extern float D_800f5e30[];

float FUN_80040e30(u32 i)
{
    return D_800f5e30[((i & 0xffff) + 0x400) & 0xfff];
}

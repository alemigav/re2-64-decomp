/* FUN_80162dd4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162dd4  body 0x80162dd4..0x80162e2b  size 88 B
 * body sha256 78fbe99fc37a0d5a86749c639f56aac4295a725dacfa2b761d0e666c43986445
 * recovered byte-exact (read from the words (M382): 22 of 22, twenty-two words, a jump-table dispatch on `p[6]` then two named calls -- the table address is the image's own, so the dispatch reads as an array of function pointers)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80162dd4.c
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

extern u32 D_80166db8[];
extern void FUN_801664d8(u8 *p);
extern void FUN_80166980(u8 *p, u32 a, u32 b);

void FUN_80162dd4(u8 *p)
{
    (*(void (**)(u8 *))(&D_80166db8[p[6]]))(p);
    FUN_801664d8(p);
    FUN_80166980(p, 4, 0);
}

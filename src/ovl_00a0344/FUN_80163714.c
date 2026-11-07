/* FUN_80163714
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163714  body 0x80163714..0x80163723  size 16 B
 * body sha256 906ee15ff85ffe03d4a4240b81456abb0449ab6185ae1480e982955188e0d13a
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80163714.c
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
void FUN_80163714(u8 *a0)
{
    *(u16 *)(a0 + 426) = *(u16 *)(a0 + 426) | 0x4400;
}

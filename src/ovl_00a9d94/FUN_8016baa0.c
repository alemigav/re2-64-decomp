/* FUN_8016baa0
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016baa0  body 0x8016baa0..0x8016bac7  size 40 B
 * body sha256 54fa269b9542efcfaf6034d28b0e297b535e0495d368a063763bf08448713f26
 * recovered byte-exact (read from the words (M379): 10 of 10, ten words, a 28-byte stride into a base whose `addiu` immediate is negative (0x8016C3AC, not 0x8017C3AC))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016baa0.c
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

extern u8 D_8016c3ac[];

void FUN_8016baa0(u32 i, u8 a, u8 b)
{
    u8 *e = D_8016c3ac + (i & 0xff) * 28;

    e[2] = a;
    e[3] = b;
}

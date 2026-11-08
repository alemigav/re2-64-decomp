/* FUN_801624a4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x801624a4  body 0x801624a4..0x801624cf  size 44 B
 * body sha256 909aa169e20c890eafce534b458413c124be5709325aa2fdab763813610a515b
 * recovered byte-exact (read from the words (M380): 11 of 11, eleven words, a state test then three stores -- the `lbu` of +703 hoists above them because the offsets prove no alias)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/801624a4.c
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

void FUN_801624a4(u8 *p)
{
    if (p[4] == 1) {
        p[5] = 2;
        *(u16 *)(p + 6) = 0;
        p[703] &= 0x7f;
    }
}

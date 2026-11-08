/* FUN_801649fc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801649fc  body 0x801649fc..0x80164a3f  size 68 B
 * body sha256 f7776c8105b23f7dabac111e80ed7925ccbdcc688c171da1909302ccd25e3d17
 * recovered byte-exact (read from the words (M381): 17 of 17, seventeen words, one guarded callee then three stores -- `$s0` saved because the context outlives the call)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801649fc.c
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

extern int FUN_8016313c(u8 *p);

void FUN_801649fc(u8 *p)
{
    if (FUN_8016313c(p) != 0) {
        p[5] = 13;
        *(u16 *)(p + 6) = 0x100;
        p[623] &= 0x7f;
    }
}

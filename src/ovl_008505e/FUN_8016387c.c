/* FUN_8016387c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016387c  body 0x8016387c..0x801638b3  size 56 B
 * body sha256 dca79ff6115f8828b343aa732c210d1b74bbb2202fe9cdc018d4992d079e59cb
 * recovered byte-exact (read from the words (M381): 14 of 14, fourteen words, an if/else whose arms are two different calls -- the shape three of the batch's entries share)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/8016387c.c
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

extern void FUN_801638b4(u8 *p);
extern void FUN_80163c44(u8 *p);

void FUN_8016387c(u8 *p)
{
    if (p[6] == 0) {
        FUN_801638b4(p);
    } else {
        FUN_80163c44(p);
    }
}

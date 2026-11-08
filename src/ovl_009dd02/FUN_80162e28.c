/* FUN_80162e28
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162e28  body 0x80162e28..0x80162e5f  size 56 B
 * body sha256 557206d8f34b824dcf85aef0e3f44dc902eeb349145ea9af137b35f35a942971
 * recovered byte-exact (read from the words (M381): 14 of 14, fourteen words, the third instance of the if/else call dispatch in this batch)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80162e28.c
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

extern void FUN_80162e60(u8 *p);
extern void FUN_80163094(u8 *p);

void FUN_80162e28(u8 *p)
{
    if (p[6] == 0) {
        FUN_80162e60(p);
    } else {
        FUN_80163094(p);
    }
}

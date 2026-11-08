/* FUN_80166338
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166338  body 0x80166338..0x8016636f  size 56 B
 * body sha256 08247cc0140eb810df46784ba19912f5a5370dcec34776abeea8a07e268252b5
 * recovered byte-exact (read from the words (M381): 14 of 14, fourteen words, a guarded init (two stores) followed by an unconditional call)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80166338.c
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

extern void FUN_80166370(u8 *p);

void FUN_80166338(u8 *p)
{
    if (p[5] == 0) {
        p[5] = 1;
        *(u32 *)p |= 2;
    }
    FUN_80166370(p);
}

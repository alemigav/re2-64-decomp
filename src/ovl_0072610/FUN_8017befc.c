/* FUN_8017befc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017befc  body 0x8017befc..0x8017bf2b  size 48 B
 * body sha256 4f5c4a452b8daf97438ce59b3ae38a418c9b8eb3c13104259c16121ca9819449
 * recovered byte-exact (read from the words (M380): 12 of 12, twelve words, a call with a constant argument, a second call with none, and the first call's result returned)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017befc.c
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

extern u32 FUN_8017bbb0(u32 n);
extern void FUN_8017bd8c(void);

u32 FUN_8017befc(void)
{
    u32 r = FUN_8017bbb0(0x20);

    FUN_8017bd8c();
    return r;
}

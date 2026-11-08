/* FUN_80164650
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164650  body 0x80164650..0x8016467f  size 48 B
 * body sha256 ccd84366d79f003d902e13a2895da60dd1a5da025ac6f82fbd9b999e06ad696e
 * recovered byte-exact (read from the words (M380): 12 of 12, twelve words, a call whose result is ignored, then two stores -- `s0` is saved only because the argument outlives the call)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80164650.c
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

extern void FUN_80163868(u8 *ctx);

void FUN_80164650(u8 *ctx)
{
    FUN_80163868(ctx);
    ctx[5] = 2;
    *(u16 *)(ctx + 6) = 0;
}

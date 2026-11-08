/* FUN_80165ff0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165ff0  body 0x80165ff0..0x8016601b  size 44 B
 * body sha256 6cab67ef7afaf138beedabd94e16fdc040d6d42b63557c937c8f1dafd50607b2
 * recovered byte-exact (read from the words (M380): 11 of 11, eleven words, one guarded two-argument call -- `sltiu` against 1800 is the test)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0087352/80165ff0.c
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

extern void FUN_80165c68(u8 *ctx, u32 n);

void FUN_80165ff0(u8 *ctx)
{
    if (*(u32 *)(ctx + 652) < 1800) {
        FUN_80165c68(ctx, 7);
    }
}

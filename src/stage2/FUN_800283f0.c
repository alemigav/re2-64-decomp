/* FUN_800283f0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800283f0  body 0x800283f0..0x8002841b  size 44 B
 * body sha256 213cf614dc066d4a82376e9af9e02de2b4686296a392a5a52dec21fec1bf82e3
 * recovered byte-exact (read from the words (M379): 11 of 11, eleven words, a method-table call at slot 0 with a 0x84 size argument, then one field cleared in the result)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800283f0.c
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

void FUN_800283f0(u8 *ctx)
{
    u8 *r = (*(u8 * (**)(u8 *, u32, u32))(*(u32 *)(ctx + 4)))(ctx, 0, 0x84);

    *(u32 *)(r + 128) = 0;
}

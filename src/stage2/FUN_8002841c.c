/* FUN_8002841c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002841c  body 0x8002841c..0x80028447  size 44 B
 * body sha256 ed4d95a754b81ae771c1f16ffb4f0bb3784b73d597c92c5a494900f0f3d675ff
 * recovered byte-exact (read from the words (M379): 11 of 11, eleven words, the same call with 0x118 and a different cleared field -- the twin of 0x800283f0)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002841c.c
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

void FUN_8002841c(u8 *ctx)
{
    u8 *r = (*(u8 * (**)(u8 *, u32, u32))(*(u32 *)(ctx + 4)))(ctx, 0, 0x118);

    *(u32 *)(r + 276) = 0;
}

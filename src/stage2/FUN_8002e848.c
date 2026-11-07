/* FUN_8002e848
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e848  body 0x8002e848..0x8002e86b  size 36 B
 * body sha256 5da2b4985f73653619cf87d3fa945df042dbc876c111c0cb79842952e74d9d9d
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, a call through a method-table slot with a 200-byte stack buffer as its second argument)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002e848.c
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

s32 FUN_8002e848(u8 *ctx)
{
    u8 buf[200];

    return (*(s32 (**)(u8 *, u8 *))(*(u32 *)ctx + 12))(ctx, buf);
}

/* FUN_8002e810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e810  body 0x8002e810..0x8002e847  size 56 B
 * body sha256 14adf73f945e45c82a70771e6fde9d129f637677493c27c4367a10417e4e4963
 * recovered byte-exact (read from the words (M376): 14 of 14, a method-table call through slot 8 followed by a named callee -- the frame is 24 bytes and holds one saved register)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002e810.c
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

extern void FUN_800283b0(u8 *ctx);

void FUN_8002e810(u8 *ctx)
{
    (*(void (**)(u8 *))(*(u32 *)ctx + 8))(ctx);
    FUN_800283b0(ctx);
}

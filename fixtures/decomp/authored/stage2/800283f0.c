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

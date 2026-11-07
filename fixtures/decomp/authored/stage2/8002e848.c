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

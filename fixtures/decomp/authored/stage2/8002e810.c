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

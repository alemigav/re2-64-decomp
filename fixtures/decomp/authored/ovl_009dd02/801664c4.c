typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_801664ec(void);

void FUN_801664c4(u8 *ctx)
{
    u32 f = *(u32 *)ctx;

    *(u16 *)(ctx + 724) = 0;
    *(u32 *)ctx = f | 0x42;
    FUN_801664ec();
}

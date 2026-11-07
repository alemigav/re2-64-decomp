typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 D_800c76b0[];

s32 FUN_80073564(u8 *ctx)
{
    u8 *t = D_800c76b0;

    *(u32 *)(ctx + 0x1c) += 1;
    return *(u16 *)(t + 0x18000 + 7476) != 0;
}

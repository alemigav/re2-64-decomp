typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

s32 FUN_80071df0(u8 *ctx)
{
    u8 *src = *(u8 **)(ctx + 0x1c);
    u8 *dst = *(u8 **)(ctx + 0x154);

    dst[0x1e9] = src[1];
    *(u32 *)(ctx + 0x1c) += 2;
    return 1;
}

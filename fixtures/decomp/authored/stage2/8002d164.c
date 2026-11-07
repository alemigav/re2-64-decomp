typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

void FUN_8002d164(u8 *ctx)
{
    u32 *p = *(u32 **)(ctx + 372);

    *(u32 *)(ctx + 352) = 0;
    p[20] = 0;
    p = *(u32 **)(ctx + 372);
    p[21] = 0;
    p = *(u32 **)(ctx + 372);
    p[23] = 0;
    *(u32 *)(ctx + 176) = 0;
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80163868(u8 *ctx);

void FUN_80164650(u8 *ctx)
{
    FUN_80163868(ctx);
    ctx[5] = 2;
    *(u16 *)(ctx + 6) = 0;
}

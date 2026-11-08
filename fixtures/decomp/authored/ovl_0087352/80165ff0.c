typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80165c68(u8 *ctx, u32 n);

void FUN_80165ff0(u8 *ctx)
{
    if (*(u32 *)(ctx + 652) < 1800) {
        FUN_80165c68(ctx, 7);
    }
}

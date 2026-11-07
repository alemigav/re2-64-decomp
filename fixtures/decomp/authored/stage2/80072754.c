typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
u32 FUN_80072754(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 1;

    return 1;
}

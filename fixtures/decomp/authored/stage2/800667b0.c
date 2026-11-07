typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

s32 FUN_800667b0(s32 a, s32 b, s32 c, s32 d)
{
    return (1 << ((u32)(a - c) >> 31)) << ((((u32)(b - d)) >> 30) & 2);
}

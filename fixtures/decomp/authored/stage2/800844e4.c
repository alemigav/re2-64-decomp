typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

u32 FUN_800844e4(u32 a)
{
    return (a << 24) | ((a & 0xff00) << 8) | ((a >> 8) & 0xff00) | (a >> 24);
}

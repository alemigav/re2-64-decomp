typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
s32 FUN_8006a8e4(u8 *a0, u8 *a1)
{
    return *(s16 *)(a1 + 2) + *(u16 *)(a1 + 6);
}

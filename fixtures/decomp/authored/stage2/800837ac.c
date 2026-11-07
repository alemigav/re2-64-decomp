typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

u32 FUN_800837ac(u32 *bits, u32 i)
{
    return bits[i >> 5] & (0x80000000u >> (i & 31));
}

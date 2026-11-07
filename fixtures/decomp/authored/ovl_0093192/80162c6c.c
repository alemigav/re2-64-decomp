typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

void FUN_80162c6c(u8 *p, u8 v)
{
    p[4] = 2;
    p[5] = v;
    p[6] = 0;
    p[7] = 0;
    p[623] |= 0x80;
}

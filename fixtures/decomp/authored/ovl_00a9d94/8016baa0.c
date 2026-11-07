typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 D_8016c3ac[];

void FUN_8016baa0(u32 i, u8 a, u8 b)
{
    u8 *e = D_8016c3ac + (i & 0xff) * 28;

    e[2] = a;
    e[3] = b;
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 D_800c76b0[];

void FUN_8003247c(u32 *p)
{
    u8 *t = D_800c76b0;

    p[0] = 0;
    p[1] = 0;
    *(u8 *)(t + 0x18000 + 6774) -= 1;
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 D_800129d4;
extern u32 FUN_800072e0(void);
extern void FUN_80007300(u32 v);

void FUN_8000e920(u32 a, u32 b, u16 c)
{
    u8 *p;
    u32 r = FUN_800072e0();

    p = (u8 *)D_800129d4;
    *(u32 *)(p + 16) = a;
    *(u32 *)(p + 20) = b;
    *(u16 *)(p + 2) = c;
    FUN_80007300(r);
}

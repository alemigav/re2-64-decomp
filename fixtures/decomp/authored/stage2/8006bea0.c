typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
extern u32 D_80139e60;

u32 FUN_8006bea0(void)
{
    return (D_80139e60 & 0x60) != 0;
}

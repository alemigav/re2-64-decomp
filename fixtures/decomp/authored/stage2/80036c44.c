typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
void FUN_80036c44(u8 *a0, u32 a1)
{
    if ((*(u32 *)(a0 + 4) & 0xffffff00u) != (a1 & 0xffffff00u))
        a0[488] = 255;
}

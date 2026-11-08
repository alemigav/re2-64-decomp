typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern int FUN_8016313c(u8 *p);

void FUN_80163100(u8 *p)
{
    if (FUN_8016313c(p) != 0) {
        p[5] = 2;
        *(u16 *)(p + 6) = 0;
        p[697] = 0;
        p[698] = 0;
    }
}

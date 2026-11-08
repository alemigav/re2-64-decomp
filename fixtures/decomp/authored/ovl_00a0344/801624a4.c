typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

void FUN_801624a4(u8 *p)
{
    if (p[4] == 1) {
        p[5] = 2;
        *(u16 *)(p + 6) = 0;
        p[703] &= 0x7f;
    }
}

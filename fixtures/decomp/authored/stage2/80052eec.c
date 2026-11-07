typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

u8 *FUN_80052eec(u8 *p)
{
    u32 i = 0;

    while (i < 32) {
        if (*p == 0) {
            break;
        }
        i++;
        p += 10;
    }
    return p;
}

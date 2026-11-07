typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

void FUN_80082474(u8 *dst, u8 *src, u32 n)
{
    u8 *end = dst + n;

    do {
        *dst++ = *src++;
    } while (dst < end);
}

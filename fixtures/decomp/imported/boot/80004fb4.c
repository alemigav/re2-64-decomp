typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
s32 func_80004FB4(u8 *dst, u8 *src)
{
    u8 *start = dst;
    s8 n;

    do {
        n = *src++;
        if (n > 0) {
            n--;
            while (n != -1) {
                *dst++ = *src++;
                n--;
            }
        } else if (n < 0) {
            u8 b = *src++;
            n++;
            while (n != 1) {
                *dst++ = b;
                n++;
            }
        }
    } while (n != 0);
    return dst - start;
}
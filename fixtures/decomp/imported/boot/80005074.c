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
s32 func_80005074(u8 *arg0, u8 *arg1)
{
    u8 *start = arg0;
    s16 n;
    u16 v;

    do {
        n = *(u16 *)arg1;
        arg1 += 2;
        if (n > 0) {
            while (--n != -1) {
                *(u16 *)arg0 = *(u16 *)arg1;
                arg1 += 2;
                arg0 += 2;
            }
        } else if (n < 0) {
            v = *(u16 *)arg1;
            arg1 += 2;
            while (++n != 1) {
                *(u16 *)arg0 = v;
                arg0 += 2;
            }
        }
    } while (n != 0);
    return arg0 - start;
}
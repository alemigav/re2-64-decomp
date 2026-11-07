/* FUN_80004fb4
 * image   boot (boot), base 0x80000480
 * address 0x80004fb4  body 0x80004fb4..0x80005073  size 192 B
 * body sha256 5c7823aebdba8fa4241114921503170b74530a48d1381db779e8a4e6d1fae76d
 * recovered byte-exact (admitted to the census (M361): 48 of 48 words, no provider range at this address (func_80004FB4))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/boot/80004fb4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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

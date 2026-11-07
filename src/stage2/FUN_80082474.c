/* FUN_80082474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082474  body 0x80082474..0x80082497  size 36 B
 * body sha256 d15b0077559bf45e900432ff766b6b770c72a4fcf9a8ed7be0fac80746e8b858
 * recovered byte-exact (read from the words (M378): 9 of 9, nine words, a do-while byte copy bounded by a precomputed end pointer)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80082474.c
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

void FUN_80082474(u8 *dst, u8 *src, u32 n)
{
    u8 *end = dst + n;

    do {
        *dst++ = *src++;
    } while (dst < end);
}

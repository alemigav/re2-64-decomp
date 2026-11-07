/* FUN_800844e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844e4  body 0x800844e4..0x8008450b  size 40 B
 * body sha256 c4cbe1ab6079d2fb7f39d794c4ec9afd3fb42f92f222fc6af2713ec7f54d2cff
 * recovered byte-exact (read from the words (M379): 10 of 10, ten words, a byte swap written as four masked terms -- the order of the four `or`s is the whole function)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800844e4.c
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

u32 FUN_800844e4(u32 a)
{
    return (a << 24) | ((a & 0xff00) << 8) | ((a >> 8) & 0xff00) | (a >> 24);
}

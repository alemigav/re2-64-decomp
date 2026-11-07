/* FUN_800837ac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800837ac  body 0x800837ac..0x800837cf  size 36 B
 * body sha256 2ada3b559f0cdd22032bfafc58469df51873a04c9f524189b8c3dd646f0ddfb7
 * recovered byte-exact (read from the words (M378): 9 of 9, nine words, a bit test: `0x80000000u >> (i & 31)` is why the mask is a `lui` and not an `ori`)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800837ac.c
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

u32 FUN_800837ac(u32 *bits, u32 i)
{
    return bits[i >> 5] & (0x80000000u >> (i & 31));
}

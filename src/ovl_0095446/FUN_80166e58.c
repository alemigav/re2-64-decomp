/* FUN_80166e58
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166e58  body 0x80166e58..0x80166e9b  size 68 B
 * body sha256 948e43cc5212201a2d1778cb8eb8940300ca9d2777e0aaa90b02bf84cb53b7c6
 * recovered byte-exact (read from the words (M381): 17 of 17, seventeen words, a flag test whose taken arm loads, clears, stores and calls, and whose other arm is one call)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0095446/80166e58.c
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

extern void FUN_801626f4(u8 *p);
extern void FUN_80166e9c(u8 *p);

void FUN_80166e58(u8 *p)
{
    if (*(u16 *)(p + 698) & 0x2000) {
        u32 v = *(u32 *)(p + 664);

        *(u16 *)(p + 498) = 0;
        *(u32 *)(p + 4) = v;
        FUN_801626f4(p);
    } else {
        FUN_80166e9c(p);
    }
}

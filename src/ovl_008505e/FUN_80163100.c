/* FUN_80163100
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80163100  body 0x80163100..0x8016313b  size 60 B
 * body sha256 aab2f8030d14f4a921bd3c0717badf1dc7b7b7d134007b6bf7829a4657af8737
 * recovered byte-exact (read from the words (M381): 15 of 15, fifteen words, the same guard and callee as `0x801649fc` with a different store set)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80163100.c
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

extern int FUN_8016313c(u8 *p);

void FUN_80163100(u8 *p)
{
    if (FUN_8016313c(p) != 0) {
        p[5] = 2;
        *(u16 *)(p + 6) = 0;
        p[697] = 0;
        p[698] = 0;
    }
}

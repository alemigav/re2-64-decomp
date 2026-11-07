/* FUN_80004c6c
 * image   boot (boot), base 0x80000480
 * address 0x80004c6c  body 0x80004c6c..0x80004c9b  size 48 B
 * body sha256 ee6c8f902e2a780f8e3f3c47bf7a8ad7dac287e2e1202ede7b85c1a9c5f02de2
 * recovered byte-exact (read from the words (M372): 12 of 12, the cohort of three (a symbol plus a two-term constant))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004c6c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 D_800c76b0[];
extern u32 D_80012884;

void FUN_80004c6c(void)
{
    u8 *t = D_800c76b0;

    D_80012884 = 0;
    *(u32 *)(t + 0x18000 + 6748) = *(u32 *)(t + 0x18000 + 6748) & ~0x20;
}

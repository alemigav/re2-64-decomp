/* FUN_800048b0
 * image   boot (boot), base 0x80000480
 * address 0x800048b0  body 0x800048b0..0x800048df  size 48 B
 * body sha256 d4be1e627d8929fe0037a512d3733870fd2bea4912ce946d83ff32e9b1a59c33
 * recovered byte-exact (read from the words (M370): 12 of 12, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/800048b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u32 FUN_800048b0(u8 *a0)
{
    u32 old = *(u32 *)(a0 + 16);
    u32 d = 0x8000 - old;

    if (d != 0) {
        *(u32 *)(a0 + 16) = 0x8000;
        *(u32 *)(a0 + 80) = *(u32 *)(a0 + 80) + d;
        *(u32 *)(a0 + 12) = *(u32 *)(a0 + 80);
    }

    return d;
}

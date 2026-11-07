/* FUN_800013b0
 * image   boot (boot), base 0x80000480
 * address 0x800013b0  body 0x800013b0..0x800013d3  size 36 B
 * body sha256 e6fda5cc8283478e5116cb77a0affaa62b1b68145742760588e9088c87c09594
 * recovered byte-exact (read from the words (M370): 9 of 9, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/800013b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 D_800138a0;
extern u32 D_800138a4;
extern u32 D_800138a8;
extern u32 D_80013eb4;

void FUN_800013b0(u32 a0)
{
    D_800138a0 = a0;
    D_800138a8 = a0;
    D_80013eb4 = 0;
    D_800138a4 = a0;
}

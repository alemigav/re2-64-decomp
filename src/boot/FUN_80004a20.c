/* FUN_80004a20
 * image   boot (boot), base 0x80000480
 * address 0x80004a20  body 0x80004a20..0x80004a4f  size 48 B
 * body sha256 285fdb10a8fbd6f451951613fdf4e3ebb76fa390286984925afc41d3048a2f92
 * recovered byte-exact (read from the words (M372): 12 of 12, the cohort of three (a symbol plus a two-term constant))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004a20.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 D_800c76b0[];
extern u32 D_80012884;

void FUN_80004a20(void)
{
    u8 *t = D_800c76b0;

    D_80012884 = 0;
    *(u32 *)(t + 0x18000 + 6748) = *(u32 *)(t + 0x18000 + 6748) & ~0x20;
}

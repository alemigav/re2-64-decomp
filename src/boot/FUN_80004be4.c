/* FUN_80004be4
 * image   boot (boot), base 0x80000480
 * address 0x80004be4  body 0x80004be4..0x80004c13  size 48 B
 * body sha256 9a76f93db6f69c122c0e41cfeb3f5a7ae10079b31ca13b88a0208e39ec2f09d6
 * recovered byte-exact (read from the words (M372): 12 of 12, the cohort of three (a symbol plus a two-term constant))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004be4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 D_800c76b0[];
extern u32 D_80012884;

void FUN_80004be4(void)
{
    u8 *t = D_800c76b0;

    D_80012884 = 0;
    *(u32 *)(t + 0x18000 + 6748) = *(u32 *)(t + 0x18000 + 6748) & ~0x20;
}

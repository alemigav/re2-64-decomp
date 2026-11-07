/* FUN_8003c170
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c170  body 0x8003c170..0x8003c187  size 24 B
 * body sha256 d54fe36b67f6671d1bde45aae8c1bfd32e83f3c5fe809f4c8bf0482cb91c62a3
 * recovered byte-exact (read from the words (M364): 6 of 6, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8003c170.c
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
void FUN_8003c170(void)
{
    u8 *p = *(u8 **)0x800ebb94;

    p[8] = 0;
    *(u16 *)(p + 12) = 0;
    p[3] = 0;
}

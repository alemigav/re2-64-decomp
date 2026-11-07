/* FUN_80036c44
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036c44  body 0x80036c44..0x80036c67  size 36 B
 * body sha256 fb7626c5d8bb4f6cdc265be472bbdb5bcc83acb6dffb9bf0275e292922593d22
 * recovered byte-exact (read from the words (M364): 9 of 9, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/80036c44.c
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
void FUN_80036c44(u8 *a0, u32 a1)
{
    if ((*(u32 *)(a0 + 4) & 0xffffff00u) != (a1 & 0xffffff00u))
        a0[488] = 255;
}

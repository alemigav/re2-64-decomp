/* FUN_80026a98
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026a98  body 0x80026a98..0x80026aa7  size 16 B
 * body sha256 3d8fad857b31978d70e694e3eb2c5b0198c40c4578d5ca92116671276cf3a2e8
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80026a98.c
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
extern u32 D_800e9130;

void FUN_80026a98(void)
{
    D_800e9130 = 1;
}

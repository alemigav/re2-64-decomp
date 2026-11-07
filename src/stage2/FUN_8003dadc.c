/* FUN_8003dadc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003dadc  body 0x8003dadc..0x8003daf3  size 24 B
 * body sha256 8842e32390b0fd096f973182a1c58a85c7386d00a70b958ac86e0455e9bc20b7
 * recovered byte-exact (read from the words (M363): 6 of 6, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8003dadc.c
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
extern u8 *D_800ebb94;

void FUN_8003dadc(void)
{
    u8 *p = D_800ebb94;

    *(u16 *)(p + 58) = *(u16 *)(p + 58) + 135;
}

/* FUN_8003aef8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003aef8  body 0x8003aef8..0x8003af0f  size 24 B
 * body sha256 f8deae4079ae12a732d3f923525f19b046cc1bd1ac184c85f2dae8aa7557fe42
 * recovered byte-exact (read from the words (M363): 6 of 6, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003aef8.c
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

void FUN_8003aef8(void)
{
    u8 *p = D_800ebb94;

    *(u16 *)(p + 4) = *(u16 *)(p + 4) + 0x100;
}

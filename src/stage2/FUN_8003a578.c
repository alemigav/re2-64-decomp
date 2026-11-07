/* FUN_8003a578
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a578  body 0x8003a578..0x8003a58f  size 24 B
 * body sha256 0e036bf7905040d9d758b3b4904f9c5ac5109bf5d5ef3dddd016477c543b6d88
 * recovered byte-exact (read from the words (M363): 6 of 6, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003a578.c
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

void FUN_8003a578(void)
{
    u8 *p = D_800ebb94;

    *(u16 *)(p + 24) = 0xa003;
    p[0] = 0;
}

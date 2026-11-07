/* FUN_80165910
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80165910  body 0x80165910..0x8016591f  size 16 B
 * body sha256 b3a499d2ff2b1e9cbab4a86f06666a0d967e4e31f5817fc382d8e0cb28bdea00
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a1414/80165910.c
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
void FUN_80165910(u8 *a0, u8 *a1)
{
    *(u32 *)a1 = *(u32 *)a1 | 0x4000;
}

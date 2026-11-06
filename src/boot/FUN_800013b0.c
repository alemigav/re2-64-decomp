/* FUN_800013b0
 * image   boot (boot), base 0x80000480
 * address 0x800013b0  body 0x800013b0..0x800013d3  size 36 B
 * body sha256 fc97b7677ea8a81b0327f9ae6d2fd8401cef02b600bc7e6b1b46ce2ca20a27f0
 * recovered byte-exact (import: 9 of 9 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800013B0_SOURCE
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
typedef float f32;
typedef double f64;


typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

extern s32 D_800138A0;
extern s32 D_800138A4;
extern s32 D_800138A8;
extern s32 D_80013EB4;

void func_800013B0(s32 arg0) {
    D_800138A0 = arg0;
    D_800138A8 = arg0;
    D_80013EB4 = 0;
    D_800138A4 = arg0;
}

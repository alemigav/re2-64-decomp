/* FUN_800844e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800844e4  body 0x800844e4..0x8008450b  size 40 B
 * body sha256 82c025900e1e45e27619f213738aa8cdf1ce09756506a207c2f8f12fe3da6164
 * recovered byte-exact (import by content alignment: 10 of 10 words at our own address (func_80084514_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800844E4_SOURCE
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

s32 func_80084514_ovl_01(u32 arg0) {
    return (arg0 << 0x18) | ((arg0 & 0xFF00) << 8) | ((arg0 >> 8) & 0xFF00) | (arg0 >> 0x18);
}

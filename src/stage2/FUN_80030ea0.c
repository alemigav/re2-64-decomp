/* FUN_80030ea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030ea0  body 0x80030ea0..0x80030edb  size 60 B
 * body sha256 7dd49b318d599499e6620d8b5e6cbd3e7c70fec89fc279f4cc9b9374e3d23da3
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80030ED0_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80030EA0_SOURCE
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

s32 func_80030ED0_ovl_01(s32 arg0, s32 arg1) {
    return (s32) ((arg0 + arg1) - 1) / arg1;
}

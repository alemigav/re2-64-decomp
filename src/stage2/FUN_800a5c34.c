/* FUN_800a5c34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c34  body 0x800a5c34..0x800a5c4f  size 28 B
 * body sha256 cc3defeac1aea08cef42f855019ac195843f57d1135b4098518befd9d836c3b4
 * recovered byte-exact (import by content alignment: 7 of 7 words at our own address (func_800A5BD4_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800A5C34_SOURCE
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

s32 func_8000EFA0();

void func_800A5BD4_ovl_01(s32 arg0, s32 arg1) {
    func_8000EFA0(arg0, arg1 * 2);
}

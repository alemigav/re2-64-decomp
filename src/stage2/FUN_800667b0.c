/* FUN_800667b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800667b0  body 0x800667b0..0x800667d3  size 36 B
 * body sha256 673b6ccf6427d8b34630624706b1e67b7c3888ae64c063df3a11722ee6707575
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_800667E0_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800667B0_SOURCE
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

s32 func_800667E0_ovl_01(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return (1 << ((u32) (arg0 - arg2) >> 0x1F)) << (((u32) (arg1 - arg3) >> 0x1E) & 2);
}

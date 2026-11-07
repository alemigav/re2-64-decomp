/* FUN_80083e60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80083e60  body 0x80083e60..0x80083e7f  size 32 B
 * body sha256 1aeb7708b0a0da5bfa7030b70af15b9f47d47cf9ede4964406d71e43c7bbd244
 * recovered byte-exact (import by content alignment: 8 of 8 words at our own address (func_80083E90_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80083E60_SOURCE
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

f32 func_80083E90_ovl_01(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 temp_fa0;
    f32 temp_fv0;

    temp_fa0 = arg2 - arg0;
    temp_fv0 = arg3 - arg1;
    return (temp_fa0 * temp_fa0) + (temp_fv0 * temp_fv0);
}

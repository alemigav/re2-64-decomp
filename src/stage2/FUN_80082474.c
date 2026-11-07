/* FUN_80082474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082474  body 0x80082474..0x80082497  size 36 B
 * body sha256 1dc973c9b5fe97b265e29bb89996f4a81f6aebf8aa0292e2cd839ac9658c3ae9
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_800824A4_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80082474_SOURCE
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

void func_800824A4_ovl_01(u8 *arg0, u8 *arg1, s32 arg2) {
    u32 temp_v1;
    u8 *var_a0;
    u8 *var_a1;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_v1 = var_a0 + arg2;
    do {
        *var_a0 = *var_a1;
        var_a0 += 1;
        var_a1 += 1;
    } while ((u32) var_a0 < temp_v1);
}

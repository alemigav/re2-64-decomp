/* FUN_8000de9c
 * image   boot (boot), base 0x80000480
 * address 0x8000de9c  body 0x8000de9c..0x8000dec3  size 40 B
 * body sha256 ca63e5a655195df36d3af3cb634f49ea61c90f3c41fcb27cec70bb4e19d5d22d
 * recovered byte-exact (import: 10 of 10 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000DE9C_SOURCE
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

u8 *func_8000DE9C(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 var_a2;
    u8 *var_a1;
    u8 *var_v1;
    u8 temp_v0;

    var_a1 = arg1;
    var_a2 = arg2;
    var_v1 = arg0;
    if (var_a2 != 0) {
        do {
            temp_v0 = *var_a1;
            var_a1 += 1;
            var_a2 -= 1;
            *var_v1 = temp_v0;
            var_v1 += 1;
        } while (var_a2 != 0);
    }
    return arg0;
}

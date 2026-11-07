/* FUN_8006087c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006087c  body 0x8006087c..0x800608c7  size 76 B
 * body sha256 d336ccb3fbb45e310dfa191e197902a12328f8304023b25d4ab5e71c38a44b03
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_800608A8_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8006087C_SOURCE
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

s32 func_800608A8_ovl_01(s32 a, s32 b, s32 c, s16 *d) {
    s16 temp_a1;
    s16 var_v1;
    s32 temp_t0;

    temp_t0 = (c + (a - b)) & 0xFFF;
    temp_a1 = b - c;
    if (temp_t0 < ((s32) (c << 0x10) >> 0xF)) {
        *d = (s16) a;
        return 0;
    }
    var_v1 = temp_a1;
    if ((u32) temp_t0 < 0x801U) {
        var_v1 = temp_a1 + (c * 2);
    }
    *d = var_v1;
    return 1;
}

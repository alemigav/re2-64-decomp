/* FUN_80052eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052eec  body 0x80052eec..0x80052f0f  size 36 B
 * body sha256 555437242b0bda203c420aded41e996329af08f2f3e3b24f2a0e2f258d6c11c7
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_80052F1C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80052EEC_SOURCE
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

u8 *func_80052F1C_ovl_01(u8 *arg0) {
    u32 var_v1;
    u8 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
loop_1:
    var_v1 += 1;
    if (*var_a0 != 0) {
        var_a0 += 0xA;
        if (var_v1 < 0x20U) {
            goto loop_1;
        }
    }
    return var_a0;
}

/* FUN_8002fc00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fc00  body 0x8002fc00..0x8002fc23  size 36 B
 * body sha256 3ff63341c7a0bd5f566a89869df24d432d7f220ec80a0aeca05e089cd7dd6f0a
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_8002FC30_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002FC00_SOURCE
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

void func_8002FC30_ovl_01(s32 arg0, s8 arg1, s32 arg2) {
    s32 var_v1;
    s8 *temp_v0;

    var_v1 = arg2 - 1;
    if (arg2 != 0) {
        do {
            temp_v0 = arg0 + var_v1;
            var_v1 -= 1;
            *temp_v0 = arg1;
        } while (var_v1 != -1);
    }
}

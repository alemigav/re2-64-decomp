/* FUN_8005c308
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c308  body 0x8005c308..0x8005c32b  size 36 B
 * body sha256 29381fbd8f331b361f348f783e00492a33b98c8f73e96490a06c8fd76eaa87e7
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_8005C338_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8005C308_SOURCE
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

void func_8005C338_ovl_01(void *arg0) {
    void *var_v1;
    unsigned int temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x234)));
    var_v1 = temp_a1 + 0x1780;
    if ((*(u8 *)((s8 *)(arg0) + (8))) & 1) {
        var_v1 = temp_a1 + 0x1D60;
    }
    (*(s8 *)((s8 *)(var_v1) + (0x112))) = 1;
}

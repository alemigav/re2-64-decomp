/* FUN_800048b0
 * image   boot (boot), base 0x80000480
 * address 0x800048b0  body 0x800048b0..0x800048df  size 48 B
 * body sha256 f52cc6ec2ea246ce79e0ab6b6927503fafb8bf944b26b6e3e8c9300345f45eba
 * recovered byte-exact (import: 12 of 12 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800048B0_SOURCE
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

s32 func_800048B0(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = 0x8000 - (*(s32 *)((s8 *)(arg0) + (0x10)));
    if (temp_v1 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x10))) = 0x8000;
        temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x50))) + temp_v1;
        (*(s32 *)((s8 *)(arg0) + (0x50))) = temp_v0;
        (*(s32 *)((s8 *)(arg0) + (0xC))) = temp_v0;
    }
    return temp_v1;
}

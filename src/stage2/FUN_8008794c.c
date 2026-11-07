/* FUN_8008794c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008794c  body 0x8008794c..0x8008799b  size 80 B
 * body sha256 fb8e429f0037678c9c38a0f1e763c78fed924528e918522bfe6d878be36d8895
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_8008797C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8008794C_SOURCE
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

void func_8008797C_ovl_01(void *arg0, void *arg1, s32 arg2) {
    if (arg2 < (*(s16 *)((s8 *)(arg0) + (0xD6)))) {
        (*(s32 *)((s8 *)(arg1) + (0xA8))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0xB8))) + (arg2 * (*(s16 *)((s8 *)(arg0) + (0xD4))) * 4));
        (*(s32 *)((s8 *)(arg1) + (0xAC))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0xBC))) + (arg2 * (*(s16 *)((s8 *)(arg0) + (0xD4))) * 4));
    }
}

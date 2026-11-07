/* FUN_80054084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80054084  body 0x80054084..0x800540d3  size 80 B
 * body sha256 2bdcc3fa0478e4bf714f5b235cb29f3aae1bd3a011cbcd39cd5a87aaa4898be9
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_800540B4_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80054084_SOURCE
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

void func_800540B4_ovl_01(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s32 *)((s8 *)(arg0) + (8))) = (s32) ((*(s32 *)((s8 *)(arg1) + (8))) + (*(u16 *)((s8 *)(arg1) + (0xA))));
    (*(s32 *)((s8 *)(arg0) + (0xC))) = (s32) (((*(u8 *)((s8 *)(arg1) + (0xC))) << 0x18) + ((*(u8 *)((s8 *)(arg1) + (0xD))) << 0x10) + ((*(u8 *)((s8 *)(arg1) + (0xE))) << 8) + (*(u8 *)((s8 *)(arg1) + (0xF))));
}

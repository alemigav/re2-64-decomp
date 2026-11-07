/* FUN_80028510
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80028510  body 0x80028510..0x8002857b  size 108 B
 * body sha256 e957d6bb4dcba067fe7ea098f99b522401d25a345b1c1771e621624244204d66
 * recovered byte-exact (import by content alignment: 27 of 27 words at our own address (func_80028540_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80028510_SOURCE
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

void func_80028540_ovl_01(void *arg0, s32 arg1, s32 arg2) {
    u32 temp_v1;

    if (arg1 == 0xFE) {
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x174)))) + (0xC))) = arg2;
        return;
    }
    temp_v1 = arg1 - 0xE0;
    if (temp_v1 < 0x10U) {
        (*(s32 *)((s8 *)(((*(void **)((s8 *)(arg0) + (0x174))) + ((temp_v1 *= 4)))) + (0x10))) = arg2;
        return;
    }
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0)))) + (0x14))) = 0x3C;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0)))) + (0x18))) = arg1;
    (*(M2C_UNK (**)())((s8 *)((*(void **)((s8 *)(arg0) + (0)))) + (0)))();
}

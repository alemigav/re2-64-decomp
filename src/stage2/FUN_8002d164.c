/* FUN_8002d164
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d164  body 0x8002d164..0x8002d187  size 36 B
 * body sha256 14e57b56c024e7a087812b1e195a14556c1ffe538594cce686c5cf29ca81bf53
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_8002D194_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002D164_SOURCE
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

void func_8002D194_ovl_01(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x174)))) + (0x50))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x174)))) + (0x54))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x174)))) + (0x5C))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0xB0))) = 0;
}

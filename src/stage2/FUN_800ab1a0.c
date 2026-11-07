/* FUN_800ab1a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab1a0  body 0x800ab1a0..0x800ab24b  size 172 B
 * body sha256 15d6c42c1a1b0fe226764e9a9492ff59f0eee787f723f4baafb1fe7c91992576
 * recovered byte-exact (import by content alignment: 43 of 43 words at our own address (func_800AB140_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800AB1A0_SOURCE
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

void func_800AB140_ovl_01(void *arg0, void *arg1, void *arg2) {
    (*(f32 *)((s8 *)(arg2) + (0))) = (f32) (((*(f32 *)((s8 *)(arg0) + (0))) * (*(f32 *)((s8 *)(arg1) + (0)))) + ((*(f32 *)((s8 *)(arg0) + (4))) * (*(f32 *)((s8 *)(arg1) + (4)))) + ((*(f32 *)((s8 *)(arg0) + (8))) * (*(f32 *)((s8 *)(arg1) + (8)))) + (*(f32 *)((s8 *)(arg0) + (0x24))));
    (*(f32 *)((s8 *)(arg2) + (4))) = (f32) (((*(f32 *)((s8 *)(arg0) + (0xC))) * (*(f32 *)((s8 *)(arg1) + (0)))) + ((*(f32 *)((s8 *)(arg0) + (0x10))) * (*(f32 *)((s8 *)(arg1) + (4)))) + ((*(f32 *)((s8 *)(arg0) + (0x14))) * (*(f32 *)((s8 *)(arg1) + (8)))) + (*(f32 *)((s8 *)(arg0) + (0x28))));
    (*(f32 *)((s8 *)(arg2) + (8))) = (f32) (((*(f32 *)((s8 *)(arg0) + (0x18))) * (*(f32 *)((s8 *)(arg1) + (0)))) + ((*(f32 *)((s8 *)(arg0) + (0x1C))) * (*(f32 *)((s8 *)(arg1) + (4)))) + ((*(f32 *)((s8 *)(arg0) + (0x20))) * (*(f32 *)((s8 *)(arg1) + (8)))) + (*(f32 *)((s8 *)(arg0) + (0x2C))));
}

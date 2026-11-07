/* FUN_800ab2cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab2cc  body 0x800ab2cc..0x800ab32f  size 100 B
 * body sha256 1bd86172562967042345217b7399eb4985f17253f47782652e95bb41ef8f30fd
 * recovered byte-exact (import by content alignment: 25 of 25 words at our own address (func_800AB26C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800AB2CC_SOURCE
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

void func_800AB26C_ovl_01(void *arg0, void *arg1, void *arg2) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (((*(f32 *)((s8 *)(arg1) + (4))) * (*(f32 *)((s8 *)(arg2) + (8)))) - ((*(f32 *)((s8 *)(arg1) + (8))) * (*(f32 *)((s8 *)(arg2) + (4)))));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (((*(f32 *)((s8 *)(arg1) + (8))) * (*(f32 *)((s8 *)(arg2) + (0)))) - ((*(f32 *)((s8 *)(arg1) + (0))) * (*(f32 *)((s8 *)(arg2) + (8)))));
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (((*(f32 *)((s8 *)(arg1) + (0))) * (*(f32 *)((s8 *)(arg2) + (4)))) - ((*(f32 *)((s8 *)(arg1) + (4))) * (*(f32 *)((s8 *)(arg2) + (0)))));
}

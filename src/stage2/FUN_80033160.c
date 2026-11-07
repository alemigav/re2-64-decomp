/* FUN_80033160
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80033160  body 0x80033160..0x800331b7  size 88 B
 * body sha256 7eef964090f33634b46cf2e8b6be34d4ef29f56033186ce55a2174b65666f8c9
 * recovered byte-exact (import by content alignment: 22 of 22 words at our own address (func_80033190_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80033160_SOURCE
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

s16 func_80032D44_overlay_001(s16, s16, s16, s16);  

s32 func_80033190_ovl_01(void *arg0, void *arg1) {
    return ((((*(s16 *)((s8 *)(arg1) + (0x66))) - func_80032D44_overlay_001((*(s16 *)((s8 *)(arg0) + (0x2A))), (*(s16 *)((s8 *)(arg0) + (0x32))), (*(s16 *)((s8 *)(arg1) + (0x2A))), (*(s16 *)((s8 *)(arg1) + (0x32))))) + 0x400) & 0xFFF) < 0x800;
}

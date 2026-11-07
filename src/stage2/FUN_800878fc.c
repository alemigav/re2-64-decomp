/* FUN_800878fc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800878fc  body 0x800878fc..0x8008794b  size 80 B
 * body sha256 7529a99ddf7fbeb685ccc65f29408ebb41d737746f4ab794b2247952a927ece2
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_8008792C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800878FC_SOURCE
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

void func_8008792C_ovl_01(void *arg0, void *arg1, s32 arg2) {
    if (arg2 < (*(s16 *)((s8 *)(arg0) + (0x5E)))) {
        (*(s32 *)((s8 *)(arg1) + (0xA8))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x40))) + (arg2 * (*(s16 *)((s8 *)(arg0) + (0x5C))) * 4));
        (*(s32 *)((s8 *)(arg1) + (0xAC))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x44))) + (arg2 * (*(s16 *)((s8 *)(arg0) + (0x5C))) * 4));
    }
}

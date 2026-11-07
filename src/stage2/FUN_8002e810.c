/* FUN_8002e810
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002e810  body 0x8002e810..0x8002e847  size 56 B
 * body sha256 1302e32ce80b64fd5f3e7680360e3ce8b3856c2739e39e11b63de2852eefcee7
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8002E840))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002E810_SOURCE
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

M2C_UNK func_800283E0_overlay_001(void **);         

void func_8002E840(void **arg0) {
    (*(M2C_UNK (**)())((s8 *)(*arg0) + (8)))();
    func_800283E0_overlay_001(arg0);
}

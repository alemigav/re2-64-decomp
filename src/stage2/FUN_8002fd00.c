/* FUN_8002fd00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fd00  body 0x8002fd00..0x8002fd37  size 56 B
 * body sha256 d952da519763fecac89cf51e1ab871e6211264e5e634fbda15b02ecef899250d
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8002FD30_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002FD00_SOURCE
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

void func_8002FD30_ovl_01(void **arg0, s32 arg1) {
    (*(s32 *)((s8 *)(*arg0) + (0x14))) = 0x2E;
    (*(s32 *)((s8 *)(*arg0) + (0x18))) = arg1;
    (*(M2C_UNK (**)())((s8 *)(*arg0) + (0)))();
}

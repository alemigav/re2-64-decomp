/* FUN_8000319c
 * image   boot (boot), base 0x80000480
 * address 0x8000319c  body 0x8000319c..0x800031c3  size 40 B
 * body sha256 eef72f22053797c661bf18a80ed4b9400b1e8297c2469f01ae64ae5e917755fb
 * recovered byte-exact (import: 10 of 10 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000319C_SOURCE
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

s32 func_8000305C();

void func_8000319C(s32 arg0, s32 arg1, s32 arg2) {
    func_8000305C(arg0, 0xE, arg1, arg2);
}

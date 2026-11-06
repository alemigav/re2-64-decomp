/* FUN_8000d66c
 * image   boot (boot), base 0x80000480
 * address 0x8000d66c  body 0x8000d66c..0x8000d697  size 44 B
 * body sha256 f2aa6743cd034efa07d468c9d5a419b767330aff43db1b2e349e3e39e2a9967b
 * recovered byte-exact (import: 11 of 11 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000D66C_SOURCE
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

s32 func_8000D9C0();                                
M2C_UNK func_8000DB10(M2C_UNK);                     

void func_8000D66C(void) {
    do {

    } while (func_8000D9C0() != 0);
    func_8000DB10(0x125);
}

/* FUN_80004ec4
 * image   boot (boot), base 0x80000480
 * address 0x80004ec4  body 0x80004ec4..0x80004edf  size 28 B
 * body sha256 88746cee85a562f4d1ac9df704efd5af864954987dc097c6ceabd0d6690541f5
 * recovered byte-exact (import: 7 of 7 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80004EC4_SOURCE
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

M2C_UNK func_80004CFC();                     

void func_80004EC4(void) {
    func_80004CFC();
}

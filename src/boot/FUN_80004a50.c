/* FUN_80004a50
 * image   boot (boot), base 0x80000480
 * address 0x80004a50  body 0x80004a50..0x80004a6b  size 28 B
 * body sha256 01e6f462fac609bf5d8bfe5ca7ea7bc7cf787af4f24ac394e1e5e3f7ea4aa496
 * recovered byte-exact (import: 7 of 7 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80004A50_SOURCE
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

M2C_UNK func_80004BAC();                     

void func_80004A50(void) {
    func_80004BAC();
}

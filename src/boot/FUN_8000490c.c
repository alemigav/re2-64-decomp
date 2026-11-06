/* FUN_8000490c
 * image   boot (boot), base 0x80000480
 * address 0x8000490c  body 0x8000490c..0x80004927  size 28 B
 * body sha256 4197146281c3d341d2de45f6112fce9dbacf52cbe0bc6418f49c3511f905b20d
 * recovered byte-exact (import: 7 of 7 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000490C_SOURCE
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

s32 func_800014AC();

void func_8000490C(s32 arg0, s32 arg1) {
    func_800014AC(arg1);
}

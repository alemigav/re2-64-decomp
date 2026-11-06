/* FUN_80004bac
 * image   boot (boot), base 0x80000480
 * address 0x80004bac  body 0x80004bac..0x80004be3  size 56 B
 * body sha256 17f791fb9f7d87a322d53faa87457771dcd68962f8d01c262f8c987d772c1615
 * recovered byte-exact (import: 14 of 14 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80004BAC_SOURCE
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
typedef void (*Fn)(void);
extern s32 D_80012884;
extern Fn D_8001288C[];

void func_80004BAC(void) {
    volatile Fn *table = D_8001288C;
    table[D_80012884]();
}

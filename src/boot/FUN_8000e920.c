/* FUN_8000e920
 * image   boot (boot), base 0x80000480
 * address 0x8000e920  body 0x8000e920..0x8000e977  size 88 B
 * body sha256 48b5af6a266d1923314716bc46157f76ae439ada53be0c8f7bc54fb48d51a53c
 * recovered byte-exact (import: 22 of 22 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000E920_SOURCE
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

s32 func_800072E0();                                
M2C_UNK func_80007300(s32);                         
extern void *D_800129D4;

void func_8000E920(s32 arg0, s32 arg1, s16 arg2) {
    s32 temp_a0;

    temp_a0 = func_800072E0();
    (*(s32 *)((s8 *)(D_800129D4) + (0x10))) = arg0;
    (*(s32 *)((s8 *)(D_800129D4) + (0x14))) = arg1;
    (*(s16 *)((s8 *)(D_800129D4) + (2))) = arg2;
    func_80007300(temp_a0);
}

/* FUN_800022bc
 * image   boot (boot), base 0x80000480
 * address 0x800022bc  body 0x800022bc..0x80002313  size 88 B
 * body sha256 48730513d37b0bd0efc9e7926549f112daa2488c6d1ce2e9bb46979809557d72
 * recovered byte-exact (import: 22 of 22 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800022BC_SOURCE
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

M2C_UNK func_80001510();                            

s32 func_800022BC(void *arg0, void *arg1) {
    func_80001510();
    (*(M2C_UNK (**)(s32, void *))((s8 *)(arg1) + (0x24)))((*(s32 *)((s8 *)(arg1) + (0x28))), (*(void **)((s8 *)(arg0) + (0x24))));
    (*(M2C_UNK (**)(s32, void *))((s8 *)(arg1) + (0x24)))((*(s32 *)((s8 *)(arg1) + (0x28))), arg0);
    return 0;
}

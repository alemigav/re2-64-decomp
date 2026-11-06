/* FUN_80002314
 * image   boot (boot), base 0x80000480
 * address 0x80002314  body 0x80002314..0x8000235f  size 76 B
 * body sha256 202353756205e7c88e5e33bc3803494aaeb43783d0ccbab3aeffffd443682bd6
 * recovered byte-exact (import: 19 of 19 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80002314_SOURCE
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

s32 func_8000DE9C();

void func_80002314(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;

    func_8000DE9C((*(s32 *)((s8 *)(arg0) + (0x24))), arg2, arg3);
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x24))) + arg3;
    (*(s32 *)((s8 *)(arg0) + (0x30))) = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = temp_v0;
}

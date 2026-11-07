/* FUN_801665a0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801665a0  body 0x801665a0..0x801665e3  size 68 B
 * body sha256 9cabcd2e63dce0ad2691bc9c068f6d79437d646433348d812ed672e712e5a069
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_80166520_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/801665a0.c
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

void func_80166520_ovl_35(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        (*(s16 *)((s8 *)(arg0) + (0x134))) = -0x320;
        (*(s16 *)((s8 *)(arg0) + (0x13A))) = 0x3E8;
        (*(s16 *)((s8 *)(arg0) + (0x12C))) = 0x320;
        (*(s16 *)((s8 *)(arg0) + (0x12E))) = 0x578;
        return;
    }
    (*(s16 *)((s8 *)(arg0) + (0x13A))) = 0x7D0;
    (*(s16 *)((s8 *)(arg0) + (0x134))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x12C))) = 4;
    (*(s16 *)((s8 *)(arg0) + (0x12E))) = 4;
}

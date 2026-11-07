/* FUN_80163498
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163498  body 0x80163498..0x801634d7  size 64 B
 * body sha256 69ab753449abe2ca2cae2adb4426d79b69fc81a072fb8b9a1103f1757dd5b81e
 * recovered byte-exact (import by content alignment: 16 of 16 words at our own address (func_8016FFA8_overlay_055, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a0344/80163498.c
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


extern int (*D_801708E0_overlay_055[])();
void func_8016FFA8_overlay_055(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0x2C8))) != 0) {
        D_801708E0_overlay_055[(*(u8 *)((s8 *)(arg0) + (5))) - 1]();
    }
}

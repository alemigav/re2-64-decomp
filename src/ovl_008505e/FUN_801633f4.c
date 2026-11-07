/* FUN_801633f4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801633f4  body 0x801633f4..0x80163427  size 52 B
 * body sha256 5bbd594f402d2bb36b7a4d78622956ad9568756c32f67e9ad5df416816ff23e4
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80163374_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/801633f4.c
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


extern int (*D_80166D48_overlay_012[])();
void func_80163374_ovl_12(void *arg0) {
    D_80166D48_overlay_012[(*(u8 *)((s8 *)(arg0) + (6)))]();
}

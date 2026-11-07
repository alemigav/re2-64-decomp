/* FUN_801623e8
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623e8  body 0x801623e8..0x80162483  size 156 B
 * body sha256 b7ec5e0adc062703613a82f6ed8533d4bd48154d840ff021aec93ab2e3c3129e
 * recovered byte-exact (import by content alignment: 39 of 39 words at our own address (func_80162368_ovl_32, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00ae24a/801623e8.c
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


extern int (*D_80166F10_overlay_032[])();
extern int (*D_80166F24_overlay_032[])();
void func_80162368_ovl_32(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    if (((*(u16 *)((s8 *)(arg0) + (0x2C2))) & 6) == 4) {
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x03000000;
        return;
    }
    D_80166F10_overlay_032[(*(u8 *)((s8 *)(arg0) + (5)))](arg0);
    D_80166F24_overlay_032[(*(u8 *)((s8 *)(arg0) + (5)))](arg0, arg1, arg2);
}

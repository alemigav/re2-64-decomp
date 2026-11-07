/* FUN_80165a0c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165a0c  body 0x80165a0c..0x80165a5b  size 80 B
 * body sha256 a73ea5f54982e16ba89ca5605f9c01e3389164c5b4d0c757e3728eca4697cef6
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_8016598C_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80165a0c.c
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

M2C_UNK func_80164D10_overlay_012();                

void func_8016598C_ovl_12(void *arg0) {
    if (((*(s32 *)((s8 *)(arg0) + (0))) & 0x18000000) && ((*(u8 *)((s8 *)(arg0) + (0x2B5))) == 0)) {
        (*(u8 *)((s8 *)(arg0) + (0x2B5))) = 1U;
        (*(s16 *)((s8 *)(arg0) + (0x1E2))) = -0x8C;
        (*(s16 *)((s8 *)(arg0) + (0x1E0))) = 0xF0;
    }
    func_80164D10_overlay_012();
}

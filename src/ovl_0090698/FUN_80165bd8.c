/* FUN_80165bd8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165bd8  body 0x80165bd8..0x80165c0b  size 52 B
 * body sha256 8cada1e3fee02f655af06b203f5fedade1151a4a2de8f4c3f9c2074372b234b1
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80165B58_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80165bd8.c
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


extern int (*D_80167F44_overlay_020[])();
void func_80165B58_ovl_17(void *arg0) {
    D_80167F44_overlay_020[(*(u8 *)((s8 *)(arg0) + (6)))]();
}

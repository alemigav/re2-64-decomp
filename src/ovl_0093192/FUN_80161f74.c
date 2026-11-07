/* FUN_80161f74
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80161f74  body 0x80161f74..0x80161fa7  size 52 B
 * body sha256 3cce761744ff97292329f7f984b79d1b96607607349080bc113d592b78ef7752
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80161EF4_ovl_18, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0093192/80161f74.c
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


extern int (*D_80162CB8_overlay_018[])();
void func_80161EF4_ovl_18(void *arg0) {
    D_80162CB8_overlay_018[(*(u8 *)((s8 *)(arg0) + (5)))]();
}

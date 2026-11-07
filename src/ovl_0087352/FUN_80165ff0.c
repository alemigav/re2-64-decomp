/* FUN_80165ff0
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80165ff0  body 0x80165ff0..0x8016601b  size 44 B
 * body sha256 0f7b04160b5ae86b6adbb4733e265ab208eb3cb70d567ced5f45f9e2f21dd4a9
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_80165F70_ovl_13, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0087352/80165ff0.c
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

s32 func_80165BE8_overlay_013();

void func_80165F70_ovl_13(void *arg0) {
    if ((u32) (*(u32 *)((s8 *)(arg0) + (0x28C))) < 0x708U) {
        func_80165BE8_overlay_013(arg0, 7);
    }
}

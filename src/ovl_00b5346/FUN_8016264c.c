/* FUN_8016264c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x8016264c  body 0x8016264c..0x80162693  size 72 B
 * body sha256 4473e9f55bc03adc4d435a97b7713fc749700e02e75d7cda3b1aff19f0a58f3c
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_801625CC_ovl_36, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b5346/8016264c.c
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


extern int (*D_80162FE8_overlay_036[])();
M2C_UNK func_80162888_overlay_036(void *);          

void func_801625CC_ovl_36(void *arg0) {
    D_80162FE8_overlay_036[(*(u8 *)((s8 *)(arg0) + (6)))]();
    func_80162888_overlay_036(arg0);
}

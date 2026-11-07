/* FUN_8016461c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016461c  body 0x8016461c..0x8016464f  size 52 B
 * body sha256 5441c20983e64df562d76a3e9f1b6e3180ac4ec06b74c1cfab0ad641632ecae3
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_8016459C_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/8016461c.c
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


extern int (*D_80167DEC_overlay_017[])();
void func_8016459C_ovl_17(void *arg0) {
    D_80167DEC_overlay_017[(*(u8 *)((s8 *)(arg0) + (5)))]();
}

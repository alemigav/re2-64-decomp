/* FUN_80163cdc
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80163cdc  body 0x80163cdc..0x80163d0f  size 52 B
 * body sha256 19380efcacb522f834ec51f8399db2c4199385b9bfac07b5a3a8b0162394633f
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80163C5C_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/80163cdc.c
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


extern int (*D_80166698_overlay_035[])();
void func_80163C5C_ovl_35(void *arg0) {
    D_80166698_overlay_035[(*(u8 *)((s8 *)(arg0) + (6)))]();
}

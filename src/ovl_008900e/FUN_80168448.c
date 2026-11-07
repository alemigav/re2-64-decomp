/* FUN_80168448
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80168448  body 0x80168448..0x8016847b  size 52 B
 * body sha256 e9dc04c3de228d458688f350d5e1257971e5135e22455ecfd73cee38809260d6
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801683C8_ovl_14, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008900e/80168448.c
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


extern int (*D_80168CCC_overlay_014[])();
void func_801683C8_ovl_14(void *arg0) {
    D_80168CCC_overlay_014[(*(u8 *)((s8 *)(arg0) + (5)))]();
}

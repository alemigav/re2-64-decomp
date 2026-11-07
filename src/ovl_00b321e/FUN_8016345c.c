/* FUN_8016345c
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x8016345c  body 0x8016345c..0x8016348f  size 52 B
 * body sha256 942dc806886779f6782d9933b6fb5a3b25ab726c7e26ea9e9a41de8d43836a3d
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801633DC_overlay_035, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/8016345c.c
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
extern volatile u32 func_80166684_ovl_33[];
void func_801633DC_overlay_035(void *arg0)
{
  unsigned short new_var;
  u32 i = *(((u8 *) arg0) + 6);
  new_var = i;
  ((void (*)(void)) func_80166684_ovl_33[new_var])();
}

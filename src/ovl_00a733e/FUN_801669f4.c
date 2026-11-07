/* FUN_801669f4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801669f4  body 0x801669f4..0x80166a2f  size 60 B
 * body sha256 77bda36d2a620b4ffbe001ac30b15131220d8c733cf8dc41860e8a8d141a7258
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80166974_ovl_30, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a733e/801669f4.c
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
typedef void (*Fn)(void *, void *, void *);
extern volatile Fn D_80167F54_overlay_030[];
void func_80166974_ovl_30(u8 *a0, void *a1, void *a2)
{
  volatile Fn *new_var;
  new_var = D_80167F54_overlay_030;
  {
  }
  new_var[a0[5]](a0, a2, a1);
}

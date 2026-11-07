/* FUN_801623b0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623b0  body 0x801623b0..0x801623e7  size 56 B
 * body sha256 76ce40707841d8d42f6ecdde1ea08a5f1c457b319abf91cfac2a51c9cce70e79
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016EEC0_overlay_060, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00ae24a/801623b0.c
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

extern int (*D_80173A9C_overlay_060[])();
void func_8016EEC0_overlay_060(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_80173A9C_overlay_060[new_var]();
}

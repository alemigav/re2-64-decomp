/* FUN_80165ab0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165ab0  body 0x80165ab0..0x80165ae7  size 56 B
 * body sha256 a5602863ed7f064c3d07ac8fdc7515f29dd5ce4b0b5e37d8b445e179e9edcb16
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_80165A30_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80165ab0.c
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
extern int (*D_80166E20_overlay_012[])();
void func_80165A30_ovl_12(void *arg0)
{
  int new_var;
  new_var = (*((u8 *) (((char *) arg0) + 5))) - 1;
  D_80166E20_overlay_012[new_var]();
}

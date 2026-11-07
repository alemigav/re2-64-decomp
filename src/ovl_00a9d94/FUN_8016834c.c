/* FUN_8016834c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016834c  body 0x8016834c..0x80168383  size 56 B
 * body sha256 a03f79e87c3140928b0f4da4dc1492151a9c94765c01530a8049ac527c7b6ac9
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801682CC_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/8016834c.c
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

extern int (*D_8016C478_overlay_031[])();
void func_801682CC_ovl_31(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 1;
  D_8016C478_overlay_031[new_var]();
}

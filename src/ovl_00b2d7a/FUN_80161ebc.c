/* FUN_80161ebc
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161ebc  body 0x80161ebc..0x80161ef3  size 56 B
 * body sha256 51bc6989e6a326a2f6a28407f1e0357e2899fee39a206c550d8f6fe2c292758c
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016E9CC_overlay_062, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b2d7a/80161ebc.c
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


extern int (*D_8016F120_overlay_062[])();
void func_8016E9CC_overlay_062(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_8016F120_overlay_062[new_var]();
}

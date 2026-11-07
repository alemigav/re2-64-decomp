/* FUN_80162624
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162624  body 0x80162624..0x8016265b  size 56 B
 * body sha256 2625f8de435bc9afb0edfd5fffe0fcef60ccf1ff1e9fa4e4e43592a9747cd19e
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016F134_overlay_056, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a1414/80162624.c
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

extern int (*D_80175A60_overlay_056[])();
void func_8016F134_overlay_056(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_80175A60_overlay_056[new_var]();
}

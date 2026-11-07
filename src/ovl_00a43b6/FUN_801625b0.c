/* FUN_801625b0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801625b0  body 0x801625b0..0x801625e7  size 56 B
 * body sha256 a6a28071b96a2d856fd7abfb27849168a8c26780a3ce90976ac0c800144a7572
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016F0C0_overlay_057, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a43b6/801625b0.c
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
extern int (*D_801762FC_overlay_057[])();
void func_8016F0C0_overlay_057(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_801762FC_overlay_057[new_var]();
}

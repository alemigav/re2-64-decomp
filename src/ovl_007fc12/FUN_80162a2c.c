/* FUN_80162a2c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162a2c  body 0x80162a2c..0x80162a63  size 56 B
 * body sha256 d0fcfde045c91c6cf12644c0737ec2dbef56434676034ad692bf2895afc2e4eb
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801629AC_ovl_11, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007fc12/80162a2c.c
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


extern int (*D_8016E0F4_overlay_011[])();
void func_801629AC_ovl_11(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_8016E0F4_overlay_011[new_var]();
}

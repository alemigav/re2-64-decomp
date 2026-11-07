/* FUN_80162434
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80162434  body 0x80162434..0x8016246b  size 56 B
 * body sha256 d85234981fa149befe5b22b40a78b8c01b97931b1a1d0663c0d0ea94049226bc
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801623B4_ovl_33, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b08a2/80162434.c
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


extern int (*D_801670B0_overlay_033[])();
void func_801623B4_ovl_33(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_801670B0_overlay_033[new_var]();
}

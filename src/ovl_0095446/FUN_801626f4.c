/* FUN_801626f4
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801626f4  body 0x801626f4..0x8016272b  size 56 B
 * body sha256 b592d1f27144a8571141a020d15e594fb3a870fc75b18fd901d279896572253b
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016F204_overlay_048, delta -51984))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0095446/801626f4.c
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

extern int (*D_80174ADC_overlay_048[])();
void func_8016F204_overlay_048(void *arg0)
{
  int new_var;
  new_var = (*((u16 *) (((char *) arg0) + 0x1AA))) & 0x3F;
  D_80174ADC_overlay_048[new_var]();
}

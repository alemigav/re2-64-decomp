/* FUN_80166590
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166590  body 0x80166590..0x801665e7  size 88 B
 * body sha256 fe0752421abdc032645394d1901de8cda78e159fc4235fcda5260f12bf634005
 * recovered byte-exact (import by content alignment: 22 of 22 words at our own address (func_80166510_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80166590.c
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
extern unsigned char D_80166EF8_ovl_12[];
void func_80166510_ovl_12(void *p, s16 d)
{
  u8 *t = D_80166EF8_ovl_12;
  s32 ix;
  u8 val;
  if (d != 0) { ix = (d > 0) * 2; } else { ix = 1; }
  val = t[ix];
  if (((u8 *)p)[0x1e8] != val) {
    ((u8 *)p)[0x1e8] = val;
    if (((u8 *)p)[0x1ea] < 7) ((u8 *)p)[0x1ea] = 15;
  }
}

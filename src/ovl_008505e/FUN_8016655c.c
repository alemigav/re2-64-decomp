/* FUN_8016655c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016655c  body 0x8016655c..0x8016658f  size 52 B
 * body sha256 a27d82fc1c4b964e9cf1422a38fd37ee25071482fed76c16e0be00e0b8da6093
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801664DC_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/8016655c.c
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
void func_801664DC_ovl_12(void *p, s32 d, s32 lim) {
  u8 *b = p;
  s16 old = *(s16 *)(b + 0x1E0);
  u16 u = *(volatile u16 *)(b + 0x1E0);
  if (lim < old) {
    s16 n = u - d;
    *(s16 *)(b + 0x1E0) = n;
    if (n < lim)
      *(s16 *)(b + 0x1E0) = lim;
  }
}

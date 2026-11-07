/* FUN_80166528
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166528  body 0x80166528..0x8016655b  size 52 B
 * body sha256 b6b98481ad0df8f4fa1c89edbd4fe712b8d759b94d97f1065a3b6bc53021170f
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801664A8_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80166528.c
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
void func_801664A8_ovl_12(void *p, s32 d, s32 lim) {
  u8 *b = p;
  s16 old = *(s16 *)(b + 0x1E0);
  u16 u = *(volatile u16 *)(b + 0x1E0);
  if (old < lim) {
    s16 n = u + d;
    *(s16 *)(b + 0x1E0) = n;
    if (lim < n)
      *(s16 *)(b + 0x1E0) = lim;
  }
}

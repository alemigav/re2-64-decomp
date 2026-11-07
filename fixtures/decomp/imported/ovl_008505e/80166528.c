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
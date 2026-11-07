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
typedef void (*Fn)(void *, void *, void *);
extern volatile Fn D_80167F54_overlay_030[];
void func_80166974_ovl_30(u8 *a0, void *a1, void *a2)
{
  volatile Fn *new_var;
  new_var = D_80167F54_overlay_030;
  {
  }
  new_var[a0[5]](a0, a2, a1);
}

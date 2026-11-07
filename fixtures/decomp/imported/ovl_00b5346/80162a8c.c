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
void func_80162888_ovl_36(void *);
extern volatile u32 D_80162FFC_ovl_36[];
void func_80162A0C_ovl_36(void *arg0)
{
  void *p = arg0;
  volatile u32 *base = D_80162FFC_ovl_36;
  u32 i = *((u8 *)p + 6);
  ((void (*)(void *))base[i])(p);
  func_80162888_ovl_36(p);
}
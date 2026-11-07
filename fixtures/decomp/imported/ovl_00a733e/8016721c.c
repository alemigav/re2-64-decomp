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
extern volatile s8 D_80167CEB_ovl_30;
s32 func_8016719C_ovl_30(s32 arg0)
{
  s8 x = D_80167CEB_ovl_30 + arg0;
  D_80167CEB_ovl_30 = x;
  if (x >= 9)
  {
    D_80167CEB_ovl_30 = 8;
    return 1;
  }
  if (x < (-8))
  {
    x = 8;
    D_80167CEB_ovl_30 = -x;
    return -1;
  }
  return 0;
}

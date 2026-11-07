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
s32 func_8017BE48_ovl_02(s32 arg0);
s32 func_8017F63C_ovl_02(void);
s32 func_8017F720_ovl_02(void);
void func_80180364_ovl_02(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80180228_ovl_02(s32 *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
  s32 temp;
  s32 helper;
  s32 f4;
  s32 f5;
  s32 f6;
  f4 = arg4;
  f5 = arg5;
  f6 = arg6;
  temp = func_8017F63C_ovl_02();
  if (arg2 != 0)
  {
    helper = 0;
    if (temp != 0)
    {
      helper = func_8017BE48_ovl_02(arg2);
    }
  }
  else
  {
    helper = 0;
  }
  func_80180364_ovl_02(arg0, arg2, temp, helper, f6);
  if (f4 != 0)
  {
    arg1[0] = func_8017F720_ovl_02();
  }
  temp = func_8017F63C_ovl_02();
  if (arg3 != 0)
  {
    helper = 0;
    if (temp != 0)
    {
      helper = func_8017BE48_ovl_02(arg3);
    }
  }
  else
  {
    helper = 0;
  }
  if (f5 != 0)
  {
    arg0[1] >>= 1;
  }
  func_80180364_ovl_02(arg0 + 1, arg3, temp, helper, f6);
  if (f5 != 0)
  {
    arg0[1] <<= 1;
  }
  if (f4 != 0)
  {
    temp = func_8017F720_ovl_02();
    arg1[1] = temp;
  }
}

/* FUN_801802a8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801802a8  body 0x801802a8..0x801803e3  size 316 B
 * body sha256 ef0b13438e9e5aaf0e50c008beb28f86d347abb77bba9747f9506ab7c4e211de
 * recovered byte-exact (import by content alignment: 79 of 79 words at our own address (func_80180228_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/801802a8.c
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

/* FUN_801833a0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801833a0  body 0x801833a0..0x80183667  size 712 B
 * body sha256 9bf2b7bba36a099418bc0158edf65fe487a28dc3f2dd777cc9bd4814373f2843
 * recovered byte-exact (import by content alignment: 178 of 178 words at our own address (func_80183320_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/801833a0.c
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
void func_80183320_ovl_02(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4)
{
  u8 *p;
  u8 *r;
  u8 *q;
  p = arg0;
  r = arg0 + arg2;
  q = arg1;
  arg2 = 0;
  if (arg4 > 0)
  {
    do
    {
      q[0] = (u8) (((q[0] + (((u32) ((p[0] + r[0]) + 1)) >> 1)) + 1) >> 1);
      q[1] = (u8) (((q[1] + (((u32) ((p[1] + r[1]) + 1)) >> 1)) + 1) >> 1);
      q[2] = (u8) (((q[2] + (((u32) ((p[2] + r[2]) + 1)) >> 1)) + 1) >> 1);
      q[3] = (u8) (((q[3] + (((u32) ((p[3] + r[3]) + 1)) >> 1)) + 1) >> 1);
      q[4] = (u8) (((q[4] + (((u32) ((p[4] + r[4]) + 1)) >> 1)) + 1) >> 1);
      q[5] = (u8) (((q[5] + (((u32) ((p[5] + r[5]) + 1)) >> 1)) + 1) >> 1);
      q[6] = (u8) (((q[6] + (((u32) ((p[6] + r[6]) + 1)) >> 1)) + 1) >> 1);
      q[7] = (u8) (((q[7] + (((u32) ((p[7] + r[7]) + 1)) >> 1)) + 1) >> 1);
      q[8] = (u8) (((q[8] + (((u32) ((p[8] + r[8]) + 1)) >> 1)) + 1) >> 1);
      q[9] = (u8) (((q[9] + (((u32) ((p[9] + r[9]) + 1)) >> 1)) + 1) >> 1);
      q[10] = (u8) (((q[10] + (((u32) ((p[10] + r[10]) + 1)) >> 1)) + 1) >> 1);
      q[11] = (u8) (((q[11] + (((u32) ((p[11] + r[11]) + 1)) >> 1)) + 1) >> 1);
      q[12] = (u8) (((q[12] + (((u32) ((p[12] + r[12]) + 1)) >> 1)) + 1) >> 1);
      q[13] = (u8) (((q[13] + (((u32) ((p[13] + r[13]) + 1)) >> 1)) + 1) >> 1);
      q[14] = (u8) (((q[14] + (((u32) ((p[14] + r[14]) + 1)) >> 1)) + 1) >> 1);
      q[15] = (u8) (((q[15] + (((u32) ((p[15] + r[15]) + 1)) >> 1)) + 1) >> 1);
      p += arg3;
      r += arg3;
      q += arg3;
      arg2++;
    }
    while (arg2 < arg4);
  }
}

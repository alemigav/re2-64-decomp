/* FUN_800351e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800351e8  body 0x800351e8..0x800352c3  size 220 B
 * body sha256 c546e463ef6cf2c0b77795cb048b5a288914d2cac2fe7ff7a8e2a2bf9ce3ed86
 * recovered byte-exact (import by content alignment: 55 of 55 words at our own address (func_80035218_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800351E8_SOURCE
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
extern s32 func_80040E88_ovl_01(void *arg0, void *arg1);
extern s32 func_8004251C_ovl_01(void *arg0, void *arg1, void *arg2);
extern s32 func_800352F4_ovl_01(s32 a0, s32 a1, s32 a2, s32 a3, s32 s4, s32 s5, s32 s6, s32 s7, s32 s8, s32 s9, s32 s10, s32 s11, s32 s12);
void func_80035218_ovl_01(u8 *arg0)
{
  volatile u8 frame[0x80];
  u8 *obj;
  u8 *adv;
  u8 *b;
  s16 sum;
  obj = *((u8 **) (arg0 + 0x234));
  adv = obj;
  adv = adv + 0x1608;
  if (!((*((s32 *) arg0)) & 0x40000))
  {
    func_80040E88_ovl_01(arg0 + 0x64, arg0 + 0x14);
  }
  b = obj + 0x38;
  func_8004251C_ovl_01(arg0 + 0x14, obj + 8, b);
  sum = (s16) ((*((u16 *) (arg0 + 0x66))) + (*((u16 *) (obj + 0x5A))));
  *((u16 *) (obj + 0x5C)) &= 0xFFF;
  func_800352F4_ovl_01((s32) adv, (s32) b, 0x190, 0x64, 0x30, 4, 0, 0x32, 0, 0x30, 6, 0, sum);
}

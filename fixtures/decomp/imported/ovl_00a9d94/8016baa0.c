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
extern s8 D_8016C32C_ovl_31;
extern s8 D_8016C600_ovl_31;
s32 func_800362C0_ovl_01();
s32 func_80036764_ovl_01();
s32 func_80036038_ovl_01();
s32 func_80040E88_ovl_01();
s32 func_8004279C_ovl_01();
void func_8016BA20_ovl_31(s32 a, s32 b, s32 c)
{
  s8 *p = (&D_8016C32C_ovl_31) + ((a & 255) * 0x1c);
  p[2] = b;
  p[3] = c;
}

void func_8016B9D4_ovl_31(void *a);
void func_8016B9A8_ovl_31(void *a, s32 b);
void func_8016B948_ovl_31(s32 a, s16 b, s32 c);
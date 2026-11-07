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
extern volatile u32 func_80166684_ovl_33[];
void func_801633DC_overlay_035(void *arg0)
{
  unsigned short new_var;
  u32 i = *(((u8 *) arg0) + 6);
  new_var = i;
  ((void (*)(void)) func_80166684_ovl_33[new_var])();
}

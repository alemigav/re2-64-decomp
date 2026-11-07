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
extern int (*D_80166E20_overlay_012[])();
void func_80165A30_ovl_12(void *arg0)
{
  int new_var;
  new_var = (*((u8 *) (((char *) arg0) + 5))) - 1;
  D_80166E20_overlay_012[new_var]();
}

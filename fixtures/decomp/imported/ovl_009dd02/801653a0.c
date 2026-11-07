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

s32 func_80164E08_overlay_026(void *arg0, s32 arg1, s32 arg2);
s32 func_80165290_ovl_26(void *arg0, s32 arg1, s32 arg2);
void func_80165320_ovl_26(void *arg0, s32 arg1, s32 arg2) {
 if (*(u8 *)((u8 *)arg0+6)==0) {
  func_80165290_ovl_26(arg0,2,6);
 }
 func_80164E08_overlay_026(arg0,arg1,arg2);
}
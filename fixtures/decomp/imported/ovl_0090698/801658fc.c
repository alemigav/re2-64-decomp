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


typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;


extern int (*D_80167EF8_overlay_017[])();
void func_8016587C_ovl_17(void *arg0) {
    D_80167EF8_overlay_017[(*(u8 *)((s8 *)(arg0) + (6)))]();
}
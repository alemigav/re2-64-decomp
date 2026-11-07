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

s32 func_80165BE8_overlay_013();

void func_80165F70_ovl_13(void *arg0) {
    if ((u32) (*(u32 *)((s8 *)(arg0) + (0x28C))) < 0x708U) {
        func_80165BE8_overlay_013(arg0, 7);
    }
}
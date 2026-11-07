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
typedef void (*Fn)(u8 *, s32, s32);
extern Fn D_80167234_ovl_33[];
void func_80165AB0_ovl_33(u8 *p, s32 x, s32 y) {
    volatile Fn *table = D_80167234_ovl_33;
    u32 n = (p[5] - 1) * 9 + p[0x26E];
    table[n](p, x, y);
}
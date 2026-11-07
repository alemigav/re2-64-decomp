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
extern u8 D_80167CEA_ovl_30;
s32 func_8016714C_ovl_30(s32 arg0){
    u8 *p = &D_80167CEA_ovl_30;
    s32 v = *p + arg0;
    *p = v;
    if ((s8)v >= 9) {
        *p = 8;
        return 1;
    }
    if ((s8)v < -8) {
        *(s8 *)p = -8;
        return -1;
    }
    return 0;
}
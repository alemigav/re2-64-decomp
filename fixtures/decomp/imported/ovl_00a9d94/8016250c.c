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


extern int (*D_8016C380_overlay_031[])();
void func_8016248C_ovl_31(void *arg0) {
    D_8016C380_overlay_031[(*(u16 *)((s8 *)(arg0) + (0x1AA))) & 0x3F]();
    if (((*(u16 *)((s8 *)(arg0) + (0x2B6))) & 0x180) == 0x100) {
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x03000000;
    }
}
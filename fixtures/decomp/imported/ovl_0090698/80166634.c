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

s32 func_801656FC_overlay_017();
s32 func_80166FBC_overlay_017();
s32 func_80167948_overlay_017();

void func_801665B4_ovl_17(void *arg0, s32 arg1, s32 arg2) {
    if ((*(u8 *)((s8 *)(arg0) + (0x2C0))) == 0) {
        func_80167948_overlay_017(arg0, 0x3F3F3F);
        (*(s8 *)((s8 *)(arg0) + (0x2D7))) = 0x1E;
        func_80166FBC_overlay_017(arg0, 0x13, 0xA);
        func_80166FBC_overlay_017(arg0, 0, 0xA);
    }
    (*(s8 *)((s8 *)(arg0) + (5))) = 2;
    func_801656FC_overlay_017(arg0, arg1, arg2);
}
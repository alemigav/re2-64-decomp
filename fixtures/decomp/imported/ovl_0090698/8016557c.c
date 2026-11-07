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

s32 func_801649F8_ovl_17();
s32 func_80166FBC_ovl_17();

void func_801654FC_ovl_17(void *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x2D7))) = 0x14;
    func_80166FBC_ovl_17(arg0, 0, 0xA);
    (*(s8 *)((s8 *)(arg0) + (5))) = 7;
    func_801649F8_ovl_17(arg0, arg1, arg2);
}
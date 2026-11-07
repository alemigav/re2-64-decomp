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

s32 func_8017BB4C_overlay_002();                    
M2C_UNK func_8017BB68_overlay_002(M2C_UNK);         

void func_8017DCF8_ovl_02(void) {
loop_1:
    if (func_8017BB4C_overlay_002() != 0) {
        func_8017BB68_overlay_002(8);
        goto loop_1;
    }
}
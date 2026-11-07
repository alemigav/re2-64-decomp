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

s32 func_8017B90C_ovl_02();                    

s32 func_8017B93C_ovl_02(void) {
    s32 temp_s0;

    temp_s0 = func_8017B90C_ovl_02();
    return (temp_s0 << 0x10) | func_8017B90C_ovl_02();
}
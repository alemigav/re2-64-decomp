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

M2C_UNK func_80162DE0_ovl_26();                     
M2C_UNK func_80163014_ovl_26();                     

void func_80162DA8_ovl_26(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_80162DE0_ovl_26();
        return;
    }
    func_80163014_ovl_26();
}
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

M2C_UNK func_80165060_ovl_30();                     
M2C_UNK func_801652F4_ovl_30(void *);               
M2C_UNK func_80167B9C_ovl_30(void *);               

void func_80165014_ovl_30(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_80165060_ovl_30();
    } else {
        func_801652F4_ovl_30(arg0);
    }
    func_80167B9C_ovl_30(arg0);
}
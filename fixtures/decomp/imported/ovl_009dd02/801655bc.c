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

M2C_UNK func_8016559C_overlay_026();                
M2C_UNK func_80165640_overlay_026(void *);          
M2C_UNK func_80166B18_overlay_026(void *, M2C_UNK, M2C_UNK); 

void func_8016553C_ovl_26(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_8016559C_overlay_026();
        if ((*(u8 *)((s8 *)(arg0) + (5))) != 1) {
            func_80166B18_overlay_026(arg0, 0xA, 1);
        }
    } else {
        func_80165640_overlay_026(arg0);
    }
}
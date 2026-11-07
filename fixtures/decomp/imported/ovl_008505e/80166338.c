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

M2C_UNK func_801662F0_overlay_012();                

void func_801662B8_ovl_12(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (5))) == 0) {
        (*(u8 *)((s8 *)(arg0) + (5))) = 1U;
        (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0))) | 2);
    }
    func_801662F0_overlay_012();
}
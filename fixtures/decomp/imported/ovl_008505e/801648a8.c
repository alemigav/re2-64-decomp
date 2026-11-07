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

s32 func_801630BC_ovl_12();                         

void func_80164828_ovl_12(void *arg0) {
    if (func_801630BC_ovl_12() != 0) {
        (*(s8 *)((s8 *)(arg0) + (5))) = 2;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x2B9))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x2C8))) = 0;
        (*(u8 *)((s8 *)(arg0) + (0x26F))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x26F))) & 0x7F);
    }
}
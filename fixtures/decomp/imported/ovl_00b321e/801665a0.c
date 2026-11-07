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

void func_80166520_ovl_35(void *arg0, s32 arg1) {
    if (arg1 == 0) {
        (*(s16 *)((s8 *)(arg0) + (0x134))) = -0x320;
        (*(s16 *)((s8 *)(arg0) + (0x13A))) = 0x3E8;
        (*(s16 *)((s8 *)(arg0) + (0x12C))) = 0x320;
        (*(s16 *)((s8 *)(arg0) + (0x12E))) = 0x578;
        return;
    }
    (*(s16 *)((s8 *)(arg0) + (0x13A))) = 0x7D0;
    (*(s16 *)((s8 *)(arg0) + (0x134))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x12C))) = 4;
    (*(s16 *)((s8 *)(arg0) + (0x12E))) = 4;
}
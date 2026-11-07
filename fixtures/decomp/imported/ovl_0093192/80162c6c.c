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

void func_80162BEC_ovl_18(void *arg0, s8 arg1) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 2;
    (*(s8 *)((s8 *)(arg0) + (5))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (6))) = 0;
    (*(s8 *)((s8 *)(arg0) + (7))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x26F))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x26F))) | 0x80);
}
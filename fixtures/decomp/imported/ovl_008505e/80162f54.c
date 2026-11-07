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

void func_80162ED4_ovl_12(void *arg0, s16 arg1, s16 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0x1F4))) = 8;
    (*(s16 *)((s8 *)(arg0) + (0x1E0))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x1E2))) = arg2;
    (*(s32 *)((s8 *)(arg0) + (0x1E8))) = 0x14000700;
    (*(s8 *)((s8 *)(arg0) + (0x2BA))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x2BB))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) (((*(s32 *)((s8 *)(arg0) + (0))) & 0xEFFFFFFF) | 0x04000000);
}
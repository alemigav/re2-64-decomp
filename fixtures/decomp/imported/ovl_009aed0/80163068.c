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

void func_80162FE8_ovl_23(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void *temp_v1;

    temp_v1 = (arg1 * 0x178) + (*(s32 *)((s8 *)(arg0) + (0x234)));
    (*(s32 *)((s8 *)(temp_v1) + (0x60))) = (s32) (((*(s32 *)((s8 *)(temp_v1) + (0x60))) & 0xFF000000) | ((arg4 << 0x10) | (arg3 << 8) | arg2));
}
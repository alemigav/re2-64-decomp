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

void func_80166540_ovl_26(s32 arg0, void *arg1) {
    u16 temp_v0;

    if ((*(u8 *)((s8 *)(arg1) + (0x13))) == 0) {
        (*(s8 *)((s8 *)(arg1) + (4))) = 1;
        temp_v0 = (*(u16 *)((s8 *)(arg1) + (6))) + (*(u8 *)((s8 *)(arg1) + (0x14)));
        (*(u16 *)((s8 *)(arg1) + (6))) = temp_v0;
        if ((s16) temp_v0 >= 0x100) {
            (*(u8 *)((s8 *)(arg1) + (0x13))) = 1U;
            (*(u16 *)((s8 *)(arg1) + (6))) = 0x100U;
        }
    }
}
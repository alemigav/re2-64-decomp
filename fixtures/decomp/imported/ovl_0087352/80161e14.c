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

void func_80161D94_ovl_13(void *arg0) {
    s32 temp_a1;
    s32 temp_lo;

    if ((*(u8 *)((s8 *)(arg0) + (4))) != 7) {
        temp_a1 = (*(s16 *)((s8 *)(arg0) + (0x25E))) - (*(s32 *)((s8 *)(arg0) + (0x2C)));
        if ((temp_a1 - 0xFA) > 0) {
            temp_lo = 0x57E40 / (s32) ((s32) (temp_a1 + 0x60E) >> 1);
            (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x208)))) + (4))) = (s32) (temp_lo | (temp_lo << 0x10));
            return;
        }
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x208)))) + (4))) = 0x01900190;
    }
}
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

extern void *D_8017E860_overlay_010;

void func_8017D8E8_ovl_10(void) {
    u16 temp_v0;

    temp_v0 = (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) + 1;
    (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) = temp_v0;
    if ((s16) temp_v0 >= 0xB5) {
        (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) = 0U;
        (*(s16 *)((s8 *)(D_8017E860_overlay_010) + (0))) = 0;
    }
}
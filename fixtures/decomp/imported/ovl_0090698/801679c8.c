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

void func_80167948_ovl_17(void *arg0, s32 arg1) {
    s32 var_v1;
    u32 var_a2;

    var_a2 = 0;
    var_v1 = 0;
    do {
        var_a2 += 1;
        (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x234))) + var_v1)) + (0x60))) = arg1;
        var_v1 += 0x178;
    } while (var_a2 < 0x14U);
}
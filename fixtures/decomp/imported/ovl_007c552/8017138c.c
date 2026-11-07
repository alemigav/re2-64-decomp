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

void func_801712D4_ovl_07(s16 **arg0) {
    char *var_v1;
    u32 var_a1;

    var_v1 = *arg0;
    var_a1 = 0;
    do {
        *(s16 *)var_v1 = 0;
        var_a1 += 1;
        var_v1 += 2;
    } while (var_a1 < 0x140U);
    *arg0 = var_v1;
}
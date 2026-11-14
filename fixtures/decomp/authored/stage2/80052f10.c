typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
u32 func_80052f10(u8 *arg0) {
    u32 var_a1;
    u32 var_v1;
    u8 *var_a0;

    var_a0 = arg0;
    var_a1 = 0;
    var_v1 = 0;
    do {
        if (*var_a0 != 0) {
            var_a1 += 1;
        }
        var_v1 += 1;
        var_a0 += 0xA;
    } while (var_v1 < 0x20U);
    return var_a1;
}

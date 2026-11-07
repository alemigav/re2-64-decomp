/* FUN_8017138c
 * image   ovl_007c552 (ovl), base 0x8016e880
 * address 0x8017138c  body 0x8017138c..0x801713af  size 36 B
 * body sha256 b25b2ba609eb2ff5276d2edd0bf5b3243c3db87665d29a8cfa43d70f21d91988
 * recovered byte-exact (import by content alignment: 9 of 9 words at our own address (func_801712D4_ovl_07, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007c552/8017138c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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

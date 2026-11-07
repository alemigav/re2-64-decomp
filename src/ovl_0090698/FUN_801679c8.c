/* FUN_801679c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801679c8  body 0x801679c8..0x801679f3  size 44 B
 * body sha256 0a7363340dbb889b127385b55c9e77ea4573de1a322dd83f58659e3ac5050197
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_80167948_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/801679c8.c
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

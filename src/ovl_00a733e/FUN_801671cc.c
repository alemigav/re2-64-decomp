/* FUN_801671cc
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801671cc  body 0x801671cc..0x8016721b  size 80 B
 * body sha256 f96dc6ce507edb9d1ce8e273323e02276b0fa0281e8623a1b86531fb0da0fa90
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_8016714C_ovl_30, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a733e/801671cc.c
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
extern u8 D_80167CEA_ovl_30;
s32 func_8016714C_ovl_30(s32 arg0){
    u8 *p = &D_80167CEA_ovl_30;
    s32 v = *p + arg0;
    *p = v;
    if ((s8)v >= 9) {
        *p = 8;
        return 1;
    }
    if ((s8)v < -8) {
        *(s8 *)p = -8;
        return -1;
    }
    return 0;
}

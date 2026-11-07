/* FUN_8017b9bc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b9bc  body 0x8017b9bc..0x8017b9eb  size 48 B
 * body sha256 1f2cab06c36d9c9c657e613eae2f1b519b88e970f15b214d149fa1a72b9b6dc1
 * recovered byte-exact (import by content alignment: 12 of 12 words at our own address (func_8017B93C_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017b9bc.c
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

s32 func_8017B90C_ovl_02();                    

s32 func_8017B93C_ovl_02(void) {
    s32 temp_s0;

    temp_s0 = func_8017B90C_ovl_02();
    return (temp_s0 << 0x10) | func_8017B90C_ovl_02();
}

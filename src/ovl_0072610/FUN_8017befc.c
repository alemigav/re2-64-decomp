/* FUN_8017befc
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017befc  body 0x8017befc..0x8017bf2b  size 48 B
 * body sha256 7f35733debd527716ba179adc2f2808564ccfea62dbda931f9a756b7703512f0
 * recovered byte-exact (import by content alignment: 12 of 12 words at our own address (func_8017BE7C_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017befc.c
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

s32 func_8017BB30_ovl_02(M2C_UNK);             
M2C_UNK func_8017BD0C_ovl_02();                

s32 func_8017BE7C_ovl_02(void) {
    s32 temp_s0;

    temp_s0 = func_8017BB30_ovl_02(0x20);
    func_8017BD0C_ovl_02();
    return temp_s0;
}

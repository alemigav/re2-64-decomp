/* FUN_8017dd78
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017dd78  body 0x8017dd78..0x8017ddab  size 52 B
 * body sha256 053cf360137e0938679f5286ce98113b979b45808c876edeb2b3998e6f6a098d
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_8017DCF8_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017dd78.c
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

s32 func_8017BB4C_overlay_002();                    
M2C_UNK func_8017BB68_overlay_002(M2C_UNK);         

void func_8017DCF8_ovl_02(void) {
loop_1:
    if (func_8017BB4C_overlay_002() != 0) {
        func_8017BB68_overlay_002(8);
        goto loop_1;
    }
}

/* FUN_8017df4c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017df4c  body 0x8017df4c..0x8017df6b  size 32 B
 * body sha256 518d6bb24feb663761ed4d3b589f72b0663a5ef8e90b18c9cc8bab5dffb4c5cd
 * recovered byte-exact (import by content alignment: 8 of 8 words at our own address (func_8017DECC_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017df4c.c
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

M2C_UNK func_8017B568_overlay_002(M2C_UNK *);       
extern M2C_UNK D_80185690_overlay_002;

void func_8017DECC_ovl_02(void) {
    func_8017B568_overlay_002(&D_80185690_overlay_002);
}

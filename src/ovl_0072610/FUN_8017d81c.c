/* FUN_8017d81c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017d81c  body 0x8017d81c..0x8017d87f  size 100 B
 * body sha256 0ad9772870167fc1a47901d888742cb11f7ee14f12554bc2621390b4aebed577
 * recovered byte-exact (import by content alignment: 25 of 25 words at our own address (func_8017D79C_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017d81c.c
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

M2C_UNK func_8017BB68_overlay_002(M2C_UNK);         
s32 func_8017BE48_overlay_002(M2C_UNK);             
extern s32 D_80185798_overlay_002;

void func_8017D79C_ovl_02(void) {
    func_8017BE48_overlay_002(3);
    if (func_8017BE48_overlay_002(1) != 0) {
        func_8017BE48_overlay_002(8);
        func_8017BE48_overlay_002(8);
        D_80185798_overlay_002 = func_8017BE48_overlay_002(8);
    }
    func_8017BE48_overlay_002(0xE);
    func_8017BB68_overlay_002(1);
    func_8017BE48_overlay_002(0xE);
}

/* FUN_8017b4f8
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017b4f8  body 0x8017b4f8..0x8017b52f  size 56 B
 * body sha256 fa72b2822b1148afc9256881d16034d38ddd0cbdb9590d331a252ea851687543
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8017B478_ovl_10, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007e132/8017b4f8.c
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


extern int (*D_8017E664_overlay_010[])();
extern u16 D_8017E682_overlay_010;

void func_8017B478_ovl_10(void) {
    D_8017E664_overlay_010[D_8017E682_overlay_010]();
}

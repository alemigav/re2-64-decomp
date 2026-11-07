/* FUN_8017bbb0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bbb0  body 0x8017bbb0..0x8017bbcb  size 28 B
 * body sha256 889965a3a2a16c1c8a018028422a7001cdb626d7a1dd286f4386d61a289e23ea
 * recovered byte-exact (import by content alignment: 7 of 7 words at our own address (func_8017BB30_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017bbb0.c
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

extern void *D_80186C14_overlay_002;

u32 func_8017BB30_ovl_02(s32 arg0) {
    return (u32) (*(u32 *)((s8 *)(D_80186C14_overlay_002) + (0xC))) >> (0x20 - arg0);
}

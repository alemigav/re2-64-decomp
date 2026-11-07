/* FUN_80162568
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80162568  body 0x80162568..0x8016259b  size 52 B
 * body sha256 67b952df6f582b7a6e75322c0776511fef1566a0d2d9a6a6f7634aa520c6e68e
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801624E8_overlay_034, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b2d7a/80162568.c
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


extern int (*D_80162A9C_overlay_034[])();
void func_801624E8_overlay_034(void *arg0) {
    D_80162A9C_overlay_034[(*(u8 *)((s8 *)(arg0) + (5)))]();
}

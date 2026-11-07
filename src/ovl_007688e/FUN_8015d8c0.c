/* FUN_8015d8c0
 * image   ovl_007688e (ovl), base 0x8015b030
 * address 0x8015d8c0  body 0x8015d8c0..0x8015d8f7  size 56 B
 * body sha256 5b04ff0efb65f64af340c11b9d148ef2b8a59ab54109e95378a5f587c822f6d7
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8015D858_ovl_03, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007688e/8015d8c0.c
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


extern int (*D_80160AF0_overlay_003[])();
extern u8 D_80160B9D_overlay_003;

void func_8015D858_ovl_03(void) {
    D_80160AF0_overlay_003[D_80160B9D_overlay_003]();
}

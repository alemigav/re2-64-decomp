/* FUN_80163834
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80163834  body 0x80163834..0x80163867  size 52 B
 * body sha256 46113dd2cf1b558dcde62e5daad3f5f1d7a38c897b8d74a298fa6892ae603d74
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801637B4_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80163834.c
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
extern volatile u32 D_80167DBC_ovl_17[];
void func_801637B4_ovl_17(void *arg0) {
    volatile u32 *base = D_80167DBC_ovl_17;
    u32 new_var;
    u32 idx = *(((u8 *)arg0) + 5);
    new_var = idx;
    ((void (*)(void))base[new_var])();
}

/* FUN_801636e8
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801636e8  body 0x801636e8..0x8016371b  size 52 B
 * body sha256 3ae49d239b6ecae26f32079ad293451b2bbb012d2d1e7eaafffb2a946c7efa7f
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80163668_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/801636e8.c
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
extern volatile u32 D_8016722C_ovl_26[];
void func_80163668_ovl_26(void *arg0) {
    volatile u32 *base = D_8016722C_ovl_26;
    u32 idx = *((u8 *)arg0 + 6);
    ((void (*)(void))base[idx])();
}

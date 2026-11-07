/* FUN_80164d00
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164d00  body 0x80164d00..0x80164d33  size 52 B
 * body sha256 409cabc302106faf2c3e55b87c8e7ad18aba2968ff42ad723feca8fdb60b37cd
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80164C80_ovl_16, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008e046/80164d00.c
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


extern int (*func_80167418_ovl_31[])();
void func_80164C80_ovl_16(void *arg0) {
    func_80167418_ovl_31[(*(u8 *)((s8 *)(arg0) + (5)))]();
}

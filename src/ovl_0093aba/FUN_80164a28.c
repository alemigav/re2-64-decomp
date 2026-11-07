/* FUN_80164a28
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164a28  body 0x80164a28..0x80164a5f  size 56 B
 * body sha256 3091430bfeb91ef15864a292e82d265e569370f8da1d207b3fd77c7699492537
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801649A8_ovl_19, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0093aba/80164a28.c
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
extern volatile u32 func_80165478_ovl_35[];
void func_801649A8_ovl_19(void *arg0) { volatile u32 *table = func_80165478_ovl_35 + 2; s32 i = *((u8 *)arg0 + 5); i -= 1; ((void (*)(void))table[i])(); }

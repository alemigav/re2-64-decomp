/* FUN_80165da0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165da0  body 0x80165da0..0x80165df7  size 88 B
 * body sha256 a2bf8c956799e5562a19e62641162bee170af3b2c704d8a32eb8095ab337b007
 * recovered byte-exact (read from the words (M382): 22 of 22, twenty-two words, one call then the same callee twice with 3 and 4 and the second argument's halves)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80165da0.c
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

extern void FUN_80165ea0(u8 *p, u8 *q);
extern void FUN_80165bd0(u8 *p, u32 a, s16 b, u32 c);

void FUN_80165da0(u8 *p, u8 *q)
{
    FUN_80165ea0(p, q);
    FUN_80165bd0(p, 3, *(s16 *)(q + 2), 0);
    FUN_80165bd0(p, 4, *(s16 *)(q + 4), 0);
}

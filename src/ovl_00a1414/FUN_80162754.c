/* FUN_80162754
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80162754  body 0x80162754..0x80162773  size 32 B
 * body sha256 9df9056658454919750bbbec2cf504f8da1c54da01f3575e4925cf776e53bc0c
 * recovered byte-exact (read from the words (M384): 8 of 8, eight words, a wrapper that loads a pointer from the context and offsets it before the call)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a1414/80162754.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_80168b3c(u8 *p, u8 *q);

void FUN_80162754(u8 *p)
{
    FUN_80168b3c(p, (u8 *)(*(u32 *)(p + 564) + 0x1a70));
}

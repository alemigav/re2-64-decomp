/* FUN_8017bbb0
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017bbb0  body 0x8017bbb0..0x8017bbcb  size 28 B
 * body sha256 267e20bf1ccb5457c90bb1c7259b73d9844bcefc42dfc17eec0896c98df57bc4
 * recovered byte-exact (read from the words (M385): 7 of 7, seven words, a scale getter: a global pointer, a depth field at +12, and `depth >> (32 - a)` -- the shift's operands are the trap, and the source order decides which register shifts)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017bbb0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 D_80186c94;

u32 FUN_8017bbb0(u32 a)
{
    u8 *p = (u8 *)D_80186c94;

    return *(u32 *)(p + 12) >> (32 - a);
}

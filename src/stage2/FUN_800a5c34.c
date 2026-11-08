/* FUN_800a5c34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5c34  body 0x800a5c34..0x800a5c4f  size 28 B
 * body sha256 c1b993367fb5e35d14f6b3877fd651f5049bfd8b499b38b6a6c903e9388de45a
 * recovered byte-exact (read from the words (M384): 7 of 7, seven words, a wrapper that doubles its second argument (`sll $a1,$a1,1` in the delay slot))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5c34.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_8000efa0(u32 a, u32 b);

void FUN_800a5c34(u32 a, u32 b)
{
    FUN_8000efa0(a, b << 1);
}

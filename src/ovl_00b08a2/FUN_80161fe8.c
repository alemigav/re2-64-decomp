/* FUN_80161fe8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80161fe8  body 0x80161fe8..0x80162017  size 48 B
 * body sha256 52c5b7b3bc54fcd36072600b5203d4f854f411b9b94590af8e4dfcfabc65d754
 * recovered byte-exact (read from the words (M379): 12 of 12, twelve words, the same guard through two loads (a pointer at +564, then its first word))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b08a2/80161fe8.c
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

extern void FUN_8016664c(void);

void FUN_80161fe8(u8 *ctx)
{
    if (*(u32 *)(*(u8 **)(ctx + 564)) & 1) {
        FUN_8016664c();
    }
}

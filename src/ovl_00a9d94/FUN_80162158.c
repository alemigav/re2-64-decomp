/* FUN_80162158
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162158  body 0x80162158..0x80162183  size 44 B
 * body sha256 abdab0327db4131a3fc01dc3a912b7c6d7d703af301858a92ecf082583d0a3c1
 * recovered byte-exact (read from the words (M379): 11 of 11, eleven words, one guarded call on bit 0 of a halfword at +426)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/80162158.c
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

extern void FUN_8016ba54(void);

void FUN_80162158(u8 *ctx)
{
    if (*(u16 *)(ctx + 426) & 1) {
        FUN_8016ba54();
    }
}

/* FUN_801664c4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801664c4  body 0x801664c4..0x801664eb  size 40 B
 * body sha256 aca8ff6e02d948113f1528a28ee7de16ef91f35dd7ec15c497b7f909bab15aab
 * recovered byte-exact (read from the words (M379): 10 of 10, ten words, a flags word read/masked/stored around a halfword clear and a `jal`)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/801664c4.c
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

extern void FUN_801664ec(void);

void FUN_801664c4(u8 *ctx)
{
    u32 f = *(u32 *)ctx;

    *(u16 *)(ctx + 724) = 0;
    *(u32 *)ctx = f | 0x42;
    FUN_801664ec();
}

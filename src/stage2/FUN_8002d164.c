/* FUN_8002d164
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002d164  body 0x8002d164..0x8002d187  size 36 B
 * body sha256 2f17aacde11d3ef5c68c4aa3cf76c7ddb29e59aa87760e2946e528431f6d3719
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, three zero-stores through a re-read pointer field -- the reload is the alias rule doing the work)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8002d164.c
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

void FUN_8002d164(u8 *ctx)
{
    u32 *p = *(u32 **)(ctx + 372);

    *(u32 *)(ctx + 352) = 0;
    p[20] = 0;
    p = *(u32 **)(ctx + 372);
    p[21] = 0;
    p = *(u32 **)(ctx + 372);
    p[23] = 0;
    *(u32 *)(ctx + 176) = 0;
}

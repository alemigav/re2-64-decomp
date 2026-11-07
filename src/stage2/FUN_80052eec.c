/* FUN_80052eec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052eec  body 0x80052eec..0x80052f0f  size 36 B
 * body sha256 f1e74ba5effdbda11e3d05bb9c49ade1cdbe6ce68ab42f1d880af859192e69fe
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, a ten-byte-stride scan capped at 32 entries -- the unsigned index is what makes it `sltiu`)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80052eec.c
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

u8 *FUN_80052eec(u8 *p)
{
    u32 i = 0;

    while (i < 32) {
        if (*p == 0) {
            break;
        }
        i++;
        p += 10;
    }
    return p;
}

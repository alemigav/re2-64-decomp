/* FUN_80043374
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80043374  body 0x80043374..0x80043397  size 36 B
 * body sha256 c1ea2bb306aca27abbbb2ed4ecfa44f7789d0e4e639a1327ae13211bc29609f5
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, a three-halfword copy out of 0x80139A80 -- the sign-extended base is the whole trap)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/80043374.c
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

extern u16 D_80139a80[];

void FUN_80043374(u16 *p)
{
    p[0] = D_80139a80[0];
    p[1] = D_80139a80[1];
    p[2] = D_80139a80[2];
}

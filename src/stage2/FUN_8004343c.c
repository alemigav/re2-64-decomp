/* FUN_8004343c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004343c  body 0x8004343c..0x8004345f  size 36 B
 * body sha256 077660ca0a9e671206441db5bb35272b7d170157e1aeb6f0282570dd46e8f0f7
 * recovered byte-exact (read from the words (M375): 9 of 9, nine words, the same three-load copy storing sign-extended halves as words)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8004343c.c
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

extern s16 D_80139a80[];

void FUN_8004343c(s32 *p)
{
    p[0] = D_80139a80[0];
    p[1] = D_80139a80[1];
    p[2] = D_80139a80[2];
}

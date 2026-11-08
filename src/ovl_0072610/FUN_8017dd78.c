/* FUN_8017dd78
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017dd78  body 0x8017dd78..0x8017ddab  size 52 B
 * body sha256 726e6e600f3a855861d7f90308a5fc15722fd599b7321c4042cef658032eb9c8
 * recovered byte-exact (read from the words (M381): 13 of 13, thirteen words, a wait loop: call, test, call-with-8, jump back -- the loop's back edge is a `j`, not a branch)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017dd78.c
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

extern u32 FUN_8017bbcc(void);
extern void FUN_8017bbe8(u32 n);

void FUN_8017dd78(void)
{
    while (FUN_8017bbcc() != 0) {
        FUN_8017bbe8(8);
    }
}

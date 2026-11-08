/* FUN_8017b7a8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b7a8  body 0x8017b7a8..0x8017b7e7  size 64 B
 * body sha256 30c81a4c7149972503263674786df2c3f4a8438243c3bc314c7d492ecbc991ef
 * recovered byte-exact (read from the words (M381): 16 of 16, sixteen words, five stores through a loaded pointer (three zeroes and one value twice) then a call with 0)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0072610/8017b7a8.c
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

extern u32 D_80186c94;
extern void FUN_8017bbe8(u32 n);

void FUN_8017b7a8(void)
{
    u8 *p = (u8 *)D_80186c94;
    u32 v = *(u32 *)p + 0x800;

    *(u32 *)(p + 16) = 0;
    *(u32 *)(p + 20) = 0;
    *(u32 *)(p + 12) = 0;
    *(u32 *)(p + 8) = v;
    *(u32 *)(p + 24) = v;
    FUN_8017bbe8(0);
}

/* FUN_8006a8e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a8e4  body 0x8006a8e4..0x8006a8f3  size 16 B
 * body sha256 d84bbac2e2f636e75c3da936f529b977743affd0d30afe0315b3f4e564e3ae67
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8006a8e4.c
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
s32 FUN_8006a8e4(u8 *a0, u8 *a1)
{
    return *(s16 *)(a1 + 2) + *(u16 *)(a1 + 6);
}

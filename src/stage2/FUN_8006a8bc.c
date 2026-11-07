/* FUN_8006a8bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006a8bc  body 0x8006a8bc..0x8006a8cb  size 16 B
 * body sha256 5707e94f8ec7a9b4c8f055c7f6472f1e0e94d4dd7f57c8e66fa47dfc7a736019
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/stage2/8006a8bc.c
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
s32 FUN_8006a8bc(u8 *a0, u8 *a1)
{
    return *(s16 *)a1 + *(u16 *)(a1 + 4);
}

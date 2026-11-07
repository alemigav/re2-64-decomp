/* FUN_8007272c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007272c  body 0x8007272c..0x8007273f  size 20 B
 * body sha256 a29c49055216a200423c1006abde83d2bd375c836f97fc4a8570b600ec3bc70f
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8007272c.c
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
u32 FUN_8007272c(u8 *a0)
{
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 4;

    return 1;
}

/* FUN_8006dd7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dd7c  body 0x8006dd7c..0x8006dda3  size 40 B
 * body sha256 1c2eb2351a3776d6ca122f67b023b131c75ac0ea7b2b1f10ed32d8cb8866ec6c
 * recovered byte-exact (read from the words (M364): 10 of 10, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006dd7c.c
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
u32 FUN_8006dd7c(u8 *a0)
{
    u8 *p = a0 + *(s8 *)(a0 + 2);

    p[8] = p[8] + 1;
    *(u32 *)(a0 + 28) = *(u32 *)(a0 + 28) + 1;

    return 1;
}

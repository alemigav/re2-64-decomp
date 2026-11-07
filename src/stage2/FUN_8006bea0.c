/* FUN_8006bea0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006bea0  body 0x8006bea0..0x8006beb3  size 20 B
 * body sha256 55703a19e8afea4db5570ec5e1c1531d03ca456487ca7b2530cd37326cbf9983
 * recovered byte-exact (read from the words (M363): 5 of 5, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8006bea0.c
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
extern u32 D_80139e60;

u32 FUN_8006bea0(void)
{
    return (D_80139e60 & 0x60) != 0;
}

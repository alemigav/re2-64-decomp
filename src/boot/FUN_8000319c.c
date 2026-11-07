/* FUN_8000319c
 * image   boot (boot), base 0x80000480
 * address 0x8000319c  body 0x8000319c..0x800031c3  size 40 B
 * body sha256 86c29a3b375086a86cccf0bdfb7ae6c24d18a92a8a3187ce320207d9566b7a80
 * recovered byte-exact (read from the words (M370): 10 of 10, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/8000319c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_8000305c(u32 a0, u32 a1, u32 a2, u32 a3);

void FUN_8000319c(u32 a0, u32 a1, u32 a2)
{
    FUN_8000305c(a0, 14, a1, a2);
}

/* FUN_800a5b7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a5b7c  body 0x800a5b7c..0x800a5ba3  size 40 B
 * body sha256 5369ee67193aac1bfca97f3263dcf0a60f19dba6b95707485b68d002970a7abf
 * recovered byte-exact (read from the words (M378): 10 of 10, ten words, a 104-byte stride into a pointer read from a global -- and an EXTENT CORRECTION: the rung said 11, but word 11 is the next function's `addiu sp,sp,-0x18` prologue, so the body ends in its own delay slot)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800a5b7c.c
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

extern u8 *D_80143f0c;

void FUN_800a5b7c(u32 i)
{
    D_80143f0c[i * 104] = 0;
}

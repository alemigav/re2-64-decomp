/* FUN_8003b640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003b640  body 0x8003b640..0x8003b66b  size 44 B
 * body sha256 afcd750c57497a990557271c5914490734fb857ea7da66b8a5e0fbc9af067ad9
 * recovered byte-exact (read from the words (M378): 11 of 11, eleven words, two halfword accumulations through one loaded pointer -- and an EXTENT CORRECTION: the rung said 12, but word 12 is the next function's `addiu sp,sp,-0x30` prologue)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/8003b640.c
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

extern u16 *D_800ebb94;

void FUN_8003b640(void)
{
    u16 *p = D_800ebb94;

    p[2] += p[9];
    p[3] += p[10];
}

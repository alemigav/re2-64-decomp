/* FUN_80004c14
 * image   boot (boot), base 0x80000480
 * address 0x80004c14  body 0x80004c14..0x80004c23  size 16 B
 * body sha256 bd9c81e7231b4fad05603fc25ba8ecef3f865cf678741cf1d20c68ddd1b61766
 * recovered byte-exact (read from the words (M363): 4 of 4, measured extent turned into a reconstruction)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004c14.c
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
extern u32 D_80012884;

void FUN_80004c14(void)
{
    D_80012884 = 2;
}

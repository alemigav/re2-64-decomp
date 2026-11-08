/* FUN_80004ec4
 * image   boot (boot), base 0x80000480
 * address 0x80004ec4  body 0x80004ec4..0x80004edf  size 28 B
 * body sha256 b22d2640f17c731175eeeeb17c53eb3508c3121b227cc0b23a17a9967f22042a
 * recovered byte-exact (read from the words (M384): 7 of 7, seven words, the same wrapper around a different callee)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004ec4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_80004cfc(void);

void FUN_80004ec4(void)
{
    FUN_80004cfc();
}

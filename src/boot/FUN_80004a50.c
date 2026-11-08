/* FUN_80004a50
 * image   boot (boot), base 0x80000480
 * address 0x80004a50  body 0x80004a50..0x80004a6b  size 28 B
 * body sha256 45cb36f8e80376612a2a9d64a6b5951d5c81167c063b5c1b27afe19ddf44fbf0
 * recovered byte-exact (read from the words (M384): 7 of 7, seven words, a plain call wrapper: frame, save `$ra`, jal, restore)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/boot/80004a50.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_80004bac(void);

void FUN_80004a50(void)
{
    FUN_80004bac();
}

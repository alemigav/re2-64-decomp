/* FUN_800284f4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800284f4  body 0x800284f4..0x8002850f  size 28 B
 * body sha256 163f93f3cb6c9b1e19f6e7d1c8766c41f3c5e136c7c9d472fa77846bddadff1f
 * recovered byte-exact (read from the words (M384): 7 of 7, seven words, a plain call wrapper)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/stage2/800284f4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_800283b0(void);

void FUN_800284f4(void)
{
    FUN_800283b0();
}

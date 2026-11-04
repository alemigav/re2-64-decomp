/* FUN_8005c264
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c264  body 0x8005c264..0x8005c27b  size 24 B
 * body sha256 336f8b5e3be321f4436adab175100c3fca7d68370b97e77adb2ab3bfaf6a807c
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8005C264_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p)
{
    u8 *b = *(u8 **)(p + 0x234);

    b += 0x1d60;
    *(u16 *)(b + 284) = 0;
    *(u8 *)(b + 274) = 0;
    *(u16 *)(b + 286) = 0;
}

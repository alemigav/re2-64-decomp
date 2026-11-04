/* FUN_80047b58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b58  body 0x80047b58..0x80047b73  size 28 B
 * body sha256 0d05f2c3c13d588a43812d91db6466b942f99ac84da795a7eb39434264451626
 * recovered byte-exact (single: 7 of 7, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80047B58_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p, u32 v)
{
    if ((u16)v)
        p[3] = 2;
    else
        p[3] = 0;
}

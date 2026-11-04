/* FUN_8008af50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008af50  body 0x8008af50..0x8008af5b  size 12 B
 * body sha256 3896b18325aed4eb30f0bb9b5161f5530d0d995116c5a2dfbff16b323aea3d92
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8008AF50_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 D_8012BD80;
void FUN_x(u32 a)
{
    D_8012BD80 = a;
}

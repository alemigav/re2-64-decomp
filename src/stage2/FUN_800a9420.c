/* FUN_800a9420
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a9420  body 0x800a9420..0x800a942b  size 12 B
 * body sha256 4bd3d81c61f2355cc8cf0bbad52475e5333b87a49e7de7990c4160c4d4c6fed5
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800A9420_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 FUN_x(u32 a)
{
    return (a + 4) << 1;
}

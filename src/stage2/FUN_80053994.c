/* FUN_80053994
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80053994  body 0x80053994..0x8005399f  size 12 B
 * body sha256 f570730be0133b3f27deb2d6a16d3b8d750783111cce4c4ead5d1b2e8e0f4a66
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80053994_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 FUN_x(u32 a)
{
    return (a & 0xff) + 63;
}

/* FUN_8008c408
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008c408  body 0x8008c408..0x8008c413  size 12 B
 * body sha256 8d0f54051f380a2d5b9102a0bb9c0a90b0f2a550af39aa1bf12997d95dd3d5ac
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8008C408_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u32 FUN_x(u32 a)
{
    return (u32)(a - 14) < 6;
}

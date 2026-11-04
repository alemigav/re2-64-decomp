/* FUN_8004786c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004786c  body 0x8004786c..0x8004787b  size 16 B
 * body sha256 dbbb94b887d5853494e0fe191f0221ed2cc4cd65dd616729269a10b755a300d9
 * recovered byte-exact (SET3_SOURCE: 4 of 4, all 3 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as SET3_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;

void FUN_store3(u8 *p, u8 a, u8 b, u8 c)
{
    p[0] = a;
    p[1] = b;
    p[2] = c;
}

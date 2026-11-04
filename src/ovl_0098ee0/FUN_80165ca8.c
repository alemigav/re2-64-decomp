/* FUN_80165ca8
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165ca8  body 0x80165ca8..0x80165caf  size 8 B
 * body sha256 f55f058ca9d2bd5b9040d08a0b2ddf7bd3b97badfe79dd511ad0ec80dff31f37
 * recovered byte-exact (CLEAR622_SOURCE: 2 of 2, all 2 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as CLEAR622_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;

void FUN_clear622(u8 *p)
{
    p[622] = 0;
}

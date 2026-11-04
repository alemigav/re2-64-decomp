/* FUN_80163b0c
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163b0c  body 0x80163b0c..0x80163b23  size 24 B
 * body sha256 9b254050b2db23d8228019a438ea75c10d0087d8bf9a4b9e2e28525de1d54dbf
 * recovered byte-exact (SET4_SOURCE: 6 of 6, all 2 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as SET4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;

void FUN_set4(u8 *p)
{
    p[4] = 3;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
}

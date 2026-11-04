/* FUN_8004d184
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004d184  body 0x8004d184..0x8004d18b  size 8 B
 * body sha256 dd5773d66c0e45e2bcbf402c2b1fa3df8ef76b8d12150cea6ca051bf8309b388
 * recovered byte-exact (clearu16: 2 of 2)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as CLEARU16_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short u16;

void FUN_clearu16(u16 *p)
{
    *p = 0;
}

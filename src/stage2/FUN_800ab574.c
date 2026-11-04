/* FUN_800ab574
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab574  body 0x800ab574..0x800ab57b  size 8 B
 * body sha256 8a3415e4b391c82426b69ab5125a7743caf55ca81907d7de32943b3b30da399b
 * recovered byte-exact (shift8: 2 of 2)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as SHIFT8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

u32 FUN_shift8(u32 a)
{
    return a >> 8;
}

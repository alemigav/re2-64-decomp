/* FUN_80035e34
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80035e34  body 0x80035e34..0x80035e3b  size 8 B
 * body sha256 c5dc119268004d909653a4bd77fe3efd046ee3f90ebf1d0af7cde4823cb7fd0d
 * recovered byte-exact (ret2: 2 of 2)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as RET2_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

u32 FUN_ret2(u32 a, u32 b)
{
    return b;
}

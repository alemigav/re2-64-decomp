/* FUN_8002fcd8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002fcd8  body 0x8002fcd8..0x8002fceb  size 20 B
 * body sha256 36cee3a35b86dcf9820ac091960d97878e49ffd66331662303f969a0177b26c0
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002FCD8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 D_800EA270;
u32 FUN_x(void)
{
    D_800EA270 = 0;
    return 1000000;
}

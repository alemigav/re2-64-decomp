/* FUN_800479bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800479bc  body 0x800479bc..0x800479c7  size 12 B
 * body sha256 101f84c34aa91c1c9d4a3519e72d68ef52e74519193f7fcad06a478a5e516b2c
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800479BC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void FUN_x(u16 *p, u16 a, u16 b)
{
    p[8] = a;
    p[9] = b;
}

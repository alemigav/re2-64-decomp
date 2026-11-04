/* FUN_80026910
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80026910  body 0x80026910..0x8002691b  size 12 B
 * body sha256 380eef1d53000eeac5e1f661be90722dbf2190c04a4af20a46fe3d9963519396
 * recovered byte-exact (single: 3 of 3, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80026910_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 D_800E9108;
void FUN_x(u32 a)
{
    D_800E9108 = a;
}

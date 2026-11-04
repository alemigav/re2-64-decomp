/* FUN_800341dc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800341dc  body 0x800341dc..0x800341eb  size 16 B
 * body sha256 59fec82e1e18b90795d30d0996d4dbe8b6168071252a14802e32a5bed2d2c5ce
 * recovered byte-exact (single: 4 of 4, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800341DC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(u8 *p, u32 b)
{
    u32 v = (p[27] | b);

    *(u32 *)(p + 24) = v;
    return v;
}

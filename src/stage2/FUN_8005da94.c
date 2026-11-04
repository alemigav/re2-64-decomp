/* FUN_8005da94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005da94  body 0x8005da94..0x8005dab7  size 36 B
 * body sha256 478c39769378d9414c0fc166b925cd8dda4f0afed7a2bb1868c08aab5ea5b23f
 * recovered byte-exact (CALL9_SOURCE: 9 of 9, all 11 copies of the identical body)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as CALL9_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern void FUN_8008cea0(unsigned int a0, unsigned int a1);

void FUN_call9(u8 *p)
{
    u16 v = *(u16 *)(p + 0x1aa);

    FUN_8008cea0(v & 0xfff, 0);
}

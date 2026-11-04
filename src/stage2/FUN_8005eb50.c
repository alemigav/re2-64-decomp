/* FUN_8005eb50
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005eb50  body 0x8005eb50..0x8005eb97  size 72 B
 * body sha256 1eb2ccee526f9dadbf2c7bc9dbfe57fac77f0ddb48d4e227870f32a1148f83d6
 * recovered byte-exact (bit18 family: 18 of 18 words; the field mask is 0x000f0000 while the bit tested is 0x00100000)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as BIT18_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

extern void FUN_80077adc(u32 a0, u32 a1);

void FUN_bit18(u32 a0)
{
    u32 v = *(u32 *)(*(u32 *)(a0 + 532));

    if (v & 0x00100000u)
        FUN_80077adc((v & 0x000f0000u) | 0x01000001u, a0 + 40);
}

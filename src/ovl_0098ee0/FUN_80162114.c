/* FUN_80162114
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80162114  body 0x80162114..0x80162143  size 48 B
 * body sha256 3260e41d399d16040c27dbd4c5a4f0573d10974f0fd450cd30d2bf40d13e164b
 * recovered byte-exact (set12 family: 12 of 12 words; the store's value is 0x03000000 (`lui`), not 0x0300)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as SET12_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

extern u32 FUN_80059e00(u32 a0, u32 a1);
extern u32 D_800e1134;

void FUN_set12(u32 a0)
{
    if (FUN_80059e00(a0, 0) & 2)
        D_800e1134 = 0x03000000;
}

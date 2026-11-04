/* FUN_80052bbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80052bbc  body 0x80052bbc..0x80052bcf  size 20 B
 * body sha256 2450fc5f0ae44db2ab089f028bfc838b885009237dbda66605dca578b995eb5b
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80052BBC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 D_800E9174[];
void FUN_x(u32 a, u16 b)
{
    u8 *p = D_800E9174;

    *(u32 *)(p + 8) = a;
    *(u16 *)(p + 12) = b;
}

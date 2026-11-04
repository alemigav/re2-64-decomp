/* FUN_80030fa4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030fa4  body 0x80030fa4..0x80030fc3  size 32 B
 * body sha256 50615f873ae1bef9f294673033e0ee8490ecc3c31f6cf814859360d5d92e52b0
 * recovered byte-exact (single: 8 of 8, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80030FA4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p, u32 n)
{
    while (n)
    {
        *p++ = 0;
        n--;
    }
}

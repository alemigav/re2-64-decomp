/* FUN_800b4d90
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b4d90  body 0x800b4d90..0x800b4dab  size 28 B
 * body sha256 42cd8fff3a21c1f8560eee5b6a57509994ce45ead8c2ba30f4ecf63067c1f39b
 * recovered byte-exact (single: 7 of 7, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800B4D90_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p)
{
    if (p[4573] == 2)
        p[4573] = 3;
}

/* FUN_80163020
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163020  body 0x80163020..0x8016303f  size 32 B
 * body sha256 b06ed1508b2384e717ac41add90e0d88deddc97070a6c48da16dd798b8d65ccc
 * recovered byte-exact (single: 8 of 8, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80163020_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p)
{
    if (*(u16 *)(p + 698) & 4)
        p[622] = 1;
    else
        p[622] = 0;
}

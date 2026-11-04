/* FUN_80047b20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b20  body 0x80047b20..0x80047b3b  size 28 B
 * body sha256 a70a505391f99b7656045f9257f74afa8732684ca643193851f8fddc89f11a33
 * recovered byte-exact (single: 7 of 7, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80047B20_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p, u32 v)
{
    if ((u16)v)
        p[7] = 2;
    else
        p[7] = 0;
}

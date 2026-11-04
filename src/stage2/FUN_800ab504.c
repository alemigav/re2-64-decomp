/* FUN_800ab504
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ab504  body 0x800ab504..0x800ab513  size 16 B
 * body sha256 adbfb666f827744a491697f99378b4173569d6ec4db7d697fde3aafa3f7daf2e
 * recovered byte-exact (single: 4 of 4, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800AB504_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(u32 *p)
{
    u32 v = *p << 8;

    *p = v;
    return v;
}

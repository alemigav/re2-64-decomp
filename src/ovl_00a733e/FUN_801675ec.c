/* FUN_801675ec
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801675ec  body 0x801675ec..0x8016760b  size 32 B
 * body sha256 de9799b697126d83d9026eda1ffc0b79598ccb71430c5a9cb3ac03bd9f873504
 * recovered byte-exact (single: 8 of 8, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_801675EC_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
extern u8 D_800E1130[];
void FUN_x(void)
{
    u8 *p = D_800E1130;

    p[4] = 3;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
}

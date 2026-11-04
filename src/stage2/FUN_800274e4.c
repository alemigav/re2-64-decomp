/* FUN_800274e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800274e4  body 0x800274e4..0x800274f7  size 20 B
 * body sha256 03cf6299e907f5291368f030bbdfdf0d52b5bf664331a0cdb4c24f7789364e3b
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_800274E4_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 D_800E9174[];
void FUN_x(u8 a, u16 b)
{
    u8 *p = D_800E9174;

    *(u16 *)(p + 214) = b;
    *(u8 *)(p + 200) = a;
}

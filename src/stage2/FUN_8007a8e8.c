/* FUN_8007a8e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007a8e8  body 0x8007a8e8..0x8007a903  size 28 B
 * body sha256 fb5cf01241468578fceb0415765412e60b0bb53ff212d5ea016774783d434f12
 * recovered byte-exact (single: 7 of 7, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8007A8E8_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u8 *p)
{
    u16 v = *(u16 *)(p + 426);

    if (v & 0x100)
        *(u16 *)(p + 426) = v & ~0x100;
}

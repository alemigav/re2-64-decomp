/* FUN_8000d9c0
 * image   boot (boot), base 0x80000480
 * address 0x8000d9c0  body 0x8000d9c0..0x8000d9d7  size 24 B
 * body sha256 9246f13040490ee6e690d36c21dc1506a24559d7aaa074d74a7f6d526b4da450
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000D9C0_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(void)
{
    return (*(volatile u32 *)0xA4040010u & 0x1cu) != 0;
}

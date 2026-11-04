/* FUN_8000d2b0
 * image   boot (boot), base 0x80000480
 * address 0x8000d2b0  body 0x8000d2b0..0x8000d2c7  size 24 B
 * body sha256 ed1d403f7e06c6e01f103ee6948eeebace2e56e4584cbde9e7011bf0503005cf
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000D2B0_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
u32 FUN_x(void)
{
    return (*(volatile u32 *)0xA4800018u & 3u) != 0;
}

/* framebuffer_set
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8008af6c  body 0x8008af6c..0x8008af7f  size 20 B
 * body sha256 99834b4ec0c3a02fad9b4060ba7c0b42f7ca58b4d2fa31690cb90786384888af
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8008AF6C_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 D_8010B6F0;
extern u32 D_8012BD84;
void FUN_x(void)
{
    D_8012BD84 = D_8010B6F0;
}

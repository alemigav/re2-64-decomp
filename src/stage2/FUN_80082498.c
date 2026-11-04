/* FUN_80082498
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80082498  body 0x80082498..0x800824af  size 24 B
 * body sha256 ff1083b1bb26f41d7751c1cdf1103b2c975f081735782dcbba2bec55934f37d2
 * recovered byte-exact (single: 6 of 6, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80082498_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef short s16;
void FUN_x(u32 *p, u32 n)
{
    do
    {
        *p++ = 0;
    } while (--n);
}

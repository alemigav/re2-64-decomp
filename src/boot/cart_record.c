/* cart_record
 * image   boot (boot), base 0x80000480
 * address 0x80001180  body 0x80001180..0x80001193  size 20 B
 * body sha256 a5783e85e964f8c5c74e647ae12eddb352a017f5ee5b1f97af5d706c14ab94b7
 * recovered byte-exact (single: 5 of 5, one draft)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80001180_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

struct rec { u32 w[4]; };

extern struct rec D_80012150[];

u32 FUN_x(u32 i)
{
    return (u32)&D_80012150[i];
}

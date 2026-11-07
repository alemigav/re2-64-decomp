/* FUN_8006b220
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006b220  body 0x8006b220..0x8006b263  size 68 B
 * body sha256 311d9f5d604c55983a7ee8584d2d5df3692e56680ae5641bb157436bb8251dc2
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_8006B250_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8006B220_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
s32 func_8006B250_ovl_01(u8 *arg0) {
    u32 x;
    s32 a;
    s32 b;

    x = *(u16 *)(arg0 + 0xA);
    b = ((x >> 6) & 0x1F) * 1800;
    a = (x >> 11) * 100;
    return -a - b;
}

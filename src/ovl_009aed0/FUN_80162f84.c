/* FUN_80162f84
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80162f84  body 0x80162f84..0x80162fe3  size 96 B
 * body sha256 2325610d80966b38101afd4bd4fad83a7436392a40a37952f308ad16c8bff4d6
 * recovered byte-exact (import by content alignment: 24 of 24 words at our own address (func_80162F04_ovl_23, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009aed0/80162f84.c
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
void func_80162F04_ovl_23(void *arg0, s32 arg1) {
    u8 *v1;
    u32 w;
    u16 x;

    v1 = *(u8 **)((u8 *)arg0 + 0x234) + arg1 * 0x178;
    w = *(u32 *)v1;
    *(u32 *)v1 = w | 0x4A;
    x = *(u16 *)((u8 *)arg0 + 0x66);
    *(u16 *)(v1 + 0x138) = 0x8000;
    *(s16 *)(v1 + 0x134) = 0;
    *(s16 *)(v1 + 0x132) = -0xA;
    *(s16 *)(v1 + 0x136) = 0;
    *(s16 *)(v1 + 0x13C) = 0;
    *(s32 *)(v1 + 0x60) = 0x202038;
    *(s16 *)(v1 + 0x130) = x + 0x800;
}

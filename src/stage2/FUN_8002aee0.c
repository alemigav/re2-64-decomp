/* FUN_8002aee0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002aee0  body 0x8002aee0..0x8002afa3  size 196 B
 * body sha256 7074e52389529594962ea1f889724d6cd4c8429ccb34ced962a8a2853a58f61d
 * recovered byte-exact (import by content alignment: 49 of 49 words at our own address (func_8002AF10_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8002AEE0_SOURCE
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
void func_8002AF10_ovl_01(u8 *p)
{
    s32 i;

    *(s32 *)(*(u8 **)p + 0x14) = 0x5E;
    (*(void (**)(u8 *, s32))(*(u8 **)p + 4))(p, 1);
    if (*(s32 *)(*(u8 **)(p + 0x174) + 0x50) != 0) {
        *(s32 *)(*(u8 **)p + 0x14) = 0x35;
        (*(void (**)(u8 *))(*(u8 **)p))(p);
    }
    for (i = 0; i < 16; i++) {
        u8 *q = p + i;
        q[0xB4] = 0;
        q[0xC4] = 1;
        q[0xD4] = 5;
    }
    *(s16 *)(p + 0xF2) = 1;
    *(s16 *)(p + 0xF4) = 1;
    *(s32 *)(p + 0xE8) = 0;
    *(s32 *)(p + 0x24) = 0;
    *(s32 *)(p + 0x100) = 0;
    *(s32 *)(p + 0xEC) = 0;
    p[0xF0] = 0;
    *(s32 *)(p + 0xF8) = 0;
    p[0xFC] = 0;
    *(s32 *)(*(u8 **)(p + 0x174) + 0x50) = 1;
}

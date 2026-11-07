/* FUN_8017ee88
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017ee88  body 0x8017ee88..0x8017eed3  size 76 B
 * body sha256 d8b0b453f61226e532f23553910d17ca9677e1d8928c06a3513825b8897318e0
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_8017EE08_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017ee88.c
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
extern u8 D_80185BDC_ovl_02[];
extern u8 D_80186614_ovl_02[];

void func_8017EE08_ovl_02(s32 arg0) {
    u16 *dst;
    u16 *src;
    s32 i;

    arg0 <<= 7;
    dst = (u16 *)(D_80185BDC_ovl_02 + arg0);
    src = (u16 *)(D_80186614_ovl_02 + arg0);
    for (i = 0; i < 0x40; i++) {
        *dst += *src;
        dst++;
        src++;
    }
}

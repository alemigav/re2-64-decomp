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
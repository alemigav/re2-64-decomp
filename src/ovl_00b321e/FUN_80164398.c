/* FUN_80164398
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164398  body 0x80164398..0x801643d3  size 60 B
 * body sha256 65a1d008b2017fe489deb6b1efdc2b859761b302688f5c15395e4e2edebc9721
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80164318_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/80164398.c
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

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;


extern int (*D_801666B4_overlay_035[])();
void func_80164318_ovl_35(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (0x64))) = 0;
    D_801666B4_overlay_035[(*(u8 *)((s8 *)(arg0) + (5))) - 1]();
}

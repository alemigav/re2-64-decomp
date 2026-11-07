/* FUN_80164c70
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164c70  body 0x80164c70..0x80164cc7  size 88 B
 * body sha256 a02ab07d4d53a10516adf773042203bb537cafd626f27616a3c36dbea1cc2fa1
 * recovered byte-exact (import by content alignment: 22 of 22 words at our own address (func_80164BF0_ovl_23, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009aed0/80164c70.c
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
typedef struct { u8 pad0[4]; volatile u8 unk4; u8 unk5; u8 pad6[0x292]; s32 unk298; } S;
extern void (*volatile D_80166588_ovl_23[])(void);
void func_80164BF0_ovl_23(S *arg0) {
    u32 value = arg0->unk298;
    *(u32 *)&arg0->unk4 = value;
    switch (arg0->unk4){case 1:{
        D_80166588_ovl_23[arg0->unk5]();
    }break;default:{
        *(u32 *)&arg0->unk4 = 0x01010000;
    }break;}
}

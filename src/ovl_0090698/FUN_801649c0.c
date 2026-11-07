/* FUN_801649c0
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801649c0  body 0x801649c0..0x80164a77  size 184 B
 * body sha256 7b97accc4c412c0c70d32b3a02bb2f3b21f6f1173bfe1a5013667c5f96f89355
 * recovered byte-exact (import by content alignment: 46 of 46 words at our own address (func_80164940_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/801649c0.c
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


s32 func_801620C8_ovl_17();
s32 func_80166FBC_ovl_17();

void func_80164940_ovl_17(void *arg0, s32 arg1, s32 arg2) {
    u8 temp_a3;
    void *temp_s0;

    temp_s0 = arg0 + 0x2B4;
    if ((*(u8 *)((s8 *)(arg0) + (0x2D8))) != 1) {
        func_80166FBC_ovl_17(arg0, 1, 0);
    }
    if ((*(u8 *)((s8 *)(temp_s0) + (0x1E))) != 0) {
        temp_a3 = (*(u8 *)((s8 *)(temp_s0) + (0x1D)));
        (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (((*(u8 *)((s8 *)(temp_s0) + (0x1B))) << 0x10) + ((*(u8 *)((s8 *)(temp_s0) + (0x1C))) << 8) + temp_a3 + 0x01000000);
        func_801620C8_ovl_17(arg0, arg1, arg2, temp_a3);
        return;
    }
    (*(s8 *)((s8 *)(temp_s0) + (0x19))) = 1;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0x01040000;
}

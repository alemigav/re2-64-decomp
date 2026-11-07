/* FUN_801813d8
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x801813d8  body 0x801813d8..0x80181413  size 60 B
 * body sha256 b9801a6b995bfce5366396d26a4844ca9145746ee8d8dbf6221d60193f5a0c41
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80181358_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/801813d8.c
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

M2C_UNK func_8017D070_overlay_002();                
M2C_UNK func_8017DD30_overlay_002(s32);             
extern s32 D_80186C18_overlay_002;

void func_80181358_ovl_02(void) {
    func_8017DD30_overlay_002(D_80186C18_overlay_002);
    D_80186C18_overlay_002 += 1;
    func_8017D070_overlay_002();
}

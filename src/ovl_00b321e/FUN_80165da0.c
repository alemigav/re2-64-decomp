/* FUN_80165da0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165da0  body 0x80165da0..0x80165df7  size 88 B
 * body sha256 65076cd86d93a67b1a34d477a6e610d71edcebbf3a913e2d979be1cad18f614e
 * recovered byte-exact (import by content alignment: 22 of 22 words at our own address (func_80165D20_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/80165da0.c
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

M2C_UNK func_80165B50_overlay_035(s32, M2C_UNK, s16, M2C_UNK); 
M2C_UNK func_80165E20_overlay_035();                

void func_80165D20_ovl_35(s32 arg0, void *arg1) {
    func_80165E20_overlay_035();
    func_80165B50_overlay_035(arg0, 3, (*(s16 *)((s8 *)(arg1) + (2))), 0);
    func_80165B50_overlay_035(arg0, 4, (*(s16 *)((s8 *)(arg1) + (4))), 0);
}

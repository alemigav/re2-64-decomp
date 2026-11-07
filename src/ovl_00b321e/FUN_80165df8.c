/* FUN_80165df8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165df8  body 0x80165df8..0x80165e9f  size 168 B
 * body sha256 13dc33d48de5f2c20dc2bfe6ef52d6253af403052bac8ad08debda22d24701f8
 * recovered byte-exact (import by content alignment: 42 of 42 words at our own address (func_80165D78_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/80165df8.c
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
M2C_UNK func_80165E20_overlay_035(s32, void *);     

void func_80165D78_ovl_35(s32 arg0, void *arg1) {
    if ((*(u8 *)((s8 *)(arg1) + (7))) == 0) {
        (*(s8 *)((s8 *)(arg1) + (1))) = 0;
    }
    func_80165E20_overlay_035(arg0, arg1);
    if ((*(s8 *)((s8 *)(arg1) + (1))) == 0) {
        if ((*(u8 *)((s8 *)(arg1) + (7))) == 2) {
            (*(s8 *)((s8 *)(arg1) + (1))) = 1;
        }
    } else if ((*(u8 *)((s8 *)(arg1) + (7))) == 1) {
        (*(u8 *)((s8 *)(arg1) + (9))) = (u8) ((*(u8 *)((s8 *)(arg1) + (9))) & 0x7F);
    }
    func_80165B50_overlay_035(arg0, 0x83, (*(s16 *)((s8 *)(arg1) + (2))), 0);
    func_80165B50_overlay_035(arg0, 0x84, (*(s16 *)((s8 *)(arg1) + (4))), 0);
}

/* FUN_80164910
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164910  body 0x80164910..0x801649bf  size 176 B
 * body sha256 0de48c347cdb4a0e14ebcd51bff155a6acead957a12d7f87e211621d9933381e
 * recovered byte-exact (import by content alignment: 44 of 44 words at our own address (func_80164890_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80164910.c
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

M2C_UNK func_801620C8_ovl_17(void *, M2C_UNK, M2C_UNK); 
M2C_UNK func_8016477C_ovl_17(void *, M2C_UNK, M2C_UNK); 
M2C_UNK func_80166FBC_ovl_17(void *, M2C_UNK, M2C_UNK); 

void func_80164890_ovl_17(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    void *temp_a0;

    temp_a0 = arg0 + 0x2B4;
    if ((*(u8 *)((s8 *)(temp_a0) + (0x1E))) != 0) {
        (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (((*(u8 *)((s8 *)(temp_a0) + (0x1B))) << 0x10) + ((*(u8 *)((s8 *)(temp_a0) + (0x1C))) << 8) + (*(u8 *)((s8 *)(temp_a0) + (0x1D))) + 0x01000000);
        if ((*(u8 *)((s8 *)(arg0) + (0x2D8))) != 1) {
            func_80166FBC_ovl_17(arg0, 0, 0);
        }
        func_801620C8_ovl_17(arg0, arg1, arg2);
        return;
    }
    func_8016477C_ovl_17(arg0, arg1, arg2);
}

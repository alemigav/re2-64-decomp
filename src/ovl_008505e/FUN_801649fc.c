/* FUN_801649fc
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801649fc  body 0x801649fc..0x80164a3f  size 68 B
 * body sha256 7ce73a711fdbaf8db500754d97fa45d710c7fd3b61a5cdc6824fcffc9f71d187
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_8016497C_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/801649fc.c
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

s32 func_801630BC_ovl_12();                         

void func_8016497C_ovl_12(void *arg0) {
    if (func_801630BC_ovl_12() != 0) {
        (*(s8 *)((s8 *)(arg0) + (5))) = 0xD;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0x100;
        (*(u8 *)((s8 *)(arg0) + (0x26F))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x26F))) & 0x7F);
    }
}

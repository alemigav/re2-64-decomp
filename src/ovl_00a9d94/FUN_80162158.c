/* FUN_80162158
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80162158  body 0x80162158..0x80162183  size 44 B
 * body sha256 531dc22193d035004f0be793e5c45426f33dadbf361c58448eb58c9f1f17f811
 * recovered byte-exact (import by content alignment: 11 of 11 words at our own address (func_801620D8_ovl_31, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a9d94/80162158.c
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

M2C_UNK func_8016B9D4_overlay_031();                

void func_801620D8_ovl_31(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x1AA))) & 1) {
        func_8016B9D4_overlay_031();
    }
}

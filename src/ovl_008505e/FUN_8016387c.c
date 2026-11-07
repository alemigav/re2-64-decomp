/* FUN_8016387c
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x8016387c  body 0x8016387c..0x801638b3  size 56 B
 * body sha256 f4f6ec3a33d0503afb9f320e9aef8139e306120f46a40a9dbb74746ab5cfed67
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_801637FC_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/8016387c.c
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

M2C_UNK func_80163834_ovl_12();                     
M2C_UNK func_80163BC4_overlay_027();                     

void func_801637FC_ovl_12(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_80163834_ovl_12();
        return;
    }
    func_80163BC4_overlay_027();
}

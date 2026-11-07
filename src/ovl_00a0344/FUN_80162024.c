/* FUN_80162024
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162024  body 0x80162024..0x8016205b  size 56 B
 * body sha256 2768807acb4276312533aed62ca7b007f82e607ab444fbc36eb879c1a328d660
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_80161FA4_ovl_27, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a0344/80162024.c
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

M2C_UNK func_80161FDC_ovl_27();                     
M2C_UNK func_80161FE4_ovl_27();                     

void func_80161FA4_ovl_27(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0x1AB))) == 0) {
        func_80161FDC_ovl_27();
        return;
    }
    func_80161FE4_ovl_27();
}

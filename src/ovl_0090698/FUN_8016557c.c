/* FUN_8016557c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016557c  body 0x8016557c..0x801655df  size 100 B
 * body sha256 6558a8d51c4c15e7f2ad72a0574dbd8efdad0fc4efc1d999935ada8567410659
 * recovered byte-exact (import by content alignment: 25 of 25 words at our own address (func_801654FC_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/8016557c.c
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

s32 func_801649F8_ovl_17();
s32 func_80166FBC_ovl_17();

void func_801654FC_ovl_17(void *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg0) + (0x2D7))) = 0x14;
    func_80166FBC_ovl_17(arg0, 0, 0xA);
    (*(s8 *)((s8 *)(arg0) + (5))) = 7;
    func_801649F8_ovl_17(arg0, arg1, arg2);
}

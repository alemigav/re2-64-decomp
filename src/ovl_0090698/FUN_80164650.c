/* FUN_80164650
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164650  body 0x80164650..0x8016467f  size 48 B
 * body sha256 b3da0ade2445536571d5fc613b1fd470d20fe789a4515eef87b7e825909e0455
 * recovered byte-exact (import by content alignment: 12 of 12 words at our own address (func_801645D0_overlay_017, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80164650.c
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

M2C_UNK func_801637E8_ovl_17();                

void func_801645D0_overlay_017(void *arg0) {
    func_801637E8_ovl_17();
    (*(s8 *)((s8 *)(arg0) + (5))) = 2;
    (*(s16 *)((s8 *)(arg0) + (6))) = 0;
}

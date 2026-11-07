/* FUN_80165094
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165094  body 0x80165094..0x801650df  size 76 B
 * body sha256 c563fded2057ee50168a0d2789a8b71e8e5cda2826e28d75dec3f3b37e98926d
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_80165014_ovl_30, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a733e/80165094.c
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

M2C_UNK func_80165060_ovl_30();                     
M2C_UNK func_801652F4_ovl_30(void *);               
M2C_UNK func_80167B9C_ovl_30(void *);               

void func_80165014_ovl_30(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_80165060_ovl_30();
    } else {
        func_801652F4_ovl_30(arg0);
    }
    func_80167B9C_ovl_30(arg0);
}

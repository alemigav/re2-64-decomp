/* FUN_80161fe8
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x80161fe8  body 0x80161fe8..0x80162017  size 48 B
 * body sha256 d16504271c2c53dc371b06bd93c9c1917739f66e491237958d22bed70a50642b
 * recovered byte-exact (import by content alignment: 12 of 12 words at our own address (func_80161F68_ovl_33, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b08a2/80161fe8.c
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

M2C_UNK func_801665CC_ovl_33();                     

void func_80161F68_ovl_33(void *arg0) {
    if (*(*(s32 **)((s8 *)(arg0) + (0x234))) & 1) {
        func_801665CC_ovl_33();
    }
}

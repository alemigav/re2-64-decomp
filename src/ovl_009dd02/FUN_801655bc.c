/* FUN_801655bc
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801655bc  body 0x801655bc..0x8016561b  size 96 B
 * body sha256 09686e15159228e0dbc1024ca67e0e921b1d686027e01f898ec1553bc00fd494
 * recovered byte-exact (import by content alignment: 24 of 24 words at our own address (func_8016553C_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/801655bc.c
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

M2C_UNK func_8016559C_overlay_026();                
M2C_UNK func_80165640_overlay_026(void *);          
M2C_UNK func_80166B18_overlay_026(void *, M2C_UNK, M2C_UNK); 

void func_8016553C_ovl_26(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        func_8016559C_overlay_026();
        if ((*(u8 *)((s8 *)(arg0) + (5))) != 1) {
            func_80166B18_overlay_026(arg0, 0xA, 1);
        }
    } else {
        func_80165640_overlay_026(arg0);
    }
}

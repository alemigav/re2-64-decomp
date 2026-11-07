/* FUN_8016577c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016577c  body 0x8016577c..0x801657c7  size 76 B
 * body sha256 e1ae705e730a159171aa95df47cb903410df7165d0015e26860ada3ef2844be5
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_801656FC_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/8016577c.c
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


extern int (*D_80167EE8_overlay_017[])();
M2C_UNK func_80165DC0_overlay_017();                

void func_801656FC_ovl_17(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0x2C0))) == 0) {
        D_80167EE8_overlay_017[(*(u8 *)((s8 *)(arg0) + (0x2BE)))]();
        return;
    }
    func_80165DC0_overlay_017();
}

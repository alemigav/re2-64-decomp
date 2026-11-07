/* FUN_80165ec8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80165ec8  body 0x80165ec8..0x80165f13  size 76 B
 * body sha256 441ec83529b36c4df8848fad2cfd807f086b6ac71f12dddb12d26942109b7896
 * recovered byte-exact (import by content alignment: 19 of 19 words at our own address (func_80165E48_ovl_17, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0090698/80165ec8.c
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


extern int (*D_80167F50_overlay_017[])();
M2C_UNK func_80166138_overlay_017();                

void func_80165E48_ovl_17(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0x2C0))) == 0) {
        D_80167F50_overlay_017[(*(u8 *)((s8 *)(arg0) + (0x2BE)))]();
        return;
    }
    func_80166138_overlay_017();
}

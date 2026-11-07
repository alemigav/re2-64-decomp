/* FUN_801623ac
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801623ac  body 0x801623ac..0x801623e3  size 56 B
 * body sha256 6bbcc10c0080cbbed7f98d78699bdaad6476bade570a0d62c13761bdbd6395a1
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8016232C_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/801623ac.c
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

void func_8016232C_ovl_35(void *arg0) {
    if (!((*(u16 *)((s8 *)(arg0) + (0x1AA))) & 1) && ((*(u8 *)((s8 *)(arg0) + (0x2C3))) != 0) && ((*(u8 *)((s8 *)(arg0) + (0x2BD))) & 1)) {
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x01060000;
    }
}

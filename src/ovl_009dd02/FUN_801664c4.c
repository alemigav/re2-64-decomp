/* FUN_801664c4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801664c4  body 0x801664c4..0x801664eb  size 40 B
 * body sha256 0dc21f606bffd01b63cb82f2199806adf055c70796e82ac68e0edcc67908e1e1
 * recovered byte-exact (import by content alignment: 10 of 10 words at our own address (func_80166444_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/801664c4.c
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

M2C_UNK func_8016646C_ovl_26();                

void func_80166444_ovl_26(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (0x2D4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0))) | 0x42);
    func_8016646C_ovl_26();
}

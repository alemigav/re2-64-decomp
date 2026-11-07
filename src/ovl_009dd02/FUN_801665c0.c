/* FUN_801665c0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801665c0  body 0x801665c0..0x80166603  size 68 B
 * body sha256 560806b31b6687f50a407530d731b69fa4df818b2e94624d5daee8cfb9906b12
 * recovered byte-exact (import by content alignment: 17 of 17 words at our own address (func_80166540_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/801665c0.c
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

void func_80166540_ovl_26(s32 arg0, void *arg1) {
    u16 temp_v0;

    if ((*(u8 *)((s8 *)(arg1) + (0x13))) == 0) {
        (*(s8 *)((s8 *)(arg1) + (4))) = 1;
        temp_v0 = (*(u16 *)((s8 *)(arg1) + (6))) + (*(u8 *)((s8 *)(arg1) + (0x14)));
        (*(u16 *)((s8 *)(arg1) + (6))) = temp_v0;
        if ((s16) temp_v0 >= 0x100) {
            (*(u8 *)((s8 *)(arg1) + (0x13))) = 1U;
            (*(u16 *)((s8 *)(arg1) + (6))) = 0x100U;
        }
    }
}

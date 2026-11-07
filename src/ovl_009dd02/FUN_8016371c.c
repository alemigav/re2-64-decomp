/* FUN_8016371c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x8016371c  body 0x8016371c..0x801637a7  size 140 B
 * body sha256 2d936aa4aa407f997eede1b9e3d18bbb90af82f515d83370cf8face265d8f91e
 * recovered byte-exact (import by content alignment: 35 of 35 words at our own address (func_8017022C_overlay_054, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/8016371c.c
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

void func_8017022C_overlay_054(void *arg0) {
    u8 var_a1;
    void *temp_a2;

    temp_a2 = arg0 + 0x2B4;
    var_a1 = (*(u8 *)((s8 *)(temp_a2) + (0x26)));
    if ((*(u8 *)((s8 *)(arg0) + (8))) != 0x2E) {
        var_a1 += 8;
    }
    (*(u8 *)((s8 *)(temp_a2) + (0xC))) = var_a1;
    (*(s8 *)((s8 *)(temp_a2) + (0xB))) = 0x5A;
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0))) & ~4);
    (*(s8 *)((s8 *)(temp_a2) + (2))) = 0;
    (*(s16 *)((s8 *)(arg0) + (6))) = 0x100;
    (*(s32 *)((s8 *)(arg0) + (0x1E8))) = (s32) (((*(u8 *)((s8 *)(arg0) + (0x2CD))) * 0x0D000000) + 0x3F00);
    if ((*(u8 *)((s8 *)(temp_a2) + (4))) == 0) {
        (*(s16 *)((s8 *)(arg0) + (6))) = 0x200;
        (*(s8 *)((s8 *)(temp_a2) + (0x12))) = 1;
        (*(s8 *)((s8 *)(temp_a2) + (0x13))) = 0;
        (*(s8 *)((s8 *)(temp_a2) + (0x14))) = 0x20;
    }
}

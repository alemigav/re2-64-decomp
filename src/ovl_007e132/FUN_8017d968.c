/* FUN_8017d968
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017d968  body 0x8017d968..0x8017d99f  size 56 B
 * body sha256 45b34c10564fc82f5abd1109acc2e7f29afd53b2138d3a3cc8650640719da697
 * recovered byte-exact (import by content alignment: 14 of 14 words at our own address (func_8017D8E8_ovl_10, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_007e132/8017d968.c
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

extern void *D_8017E860_overlay_010;

void func_8017D8E8_ovl_10(void) {
    u16 temp_v0;

    temp_v0 = (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) + 1;
    (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) = temp_v0;
    if ((s16) temp_v0 >= 0xB5) {
        (*(u16 *)((s8 *)(D_8017E860_overlay_010) + (2))) = 0U;
        (*(s16 *)((s8 *)(D_8017E860_overlay_010) + (0))) = 0;
    }
}

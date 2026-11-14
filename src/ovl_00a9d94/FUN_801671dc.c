/* FUN_801671dc
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801671dc  body 0x801671dc..0x80167227  size 76 B
 * body sha256 21e220d997144ddf0f64774e0636133660cd60c239a1d40a567f948721754068
 * recovered byte-exact (imported: m2c's draft, better than the provider's (15 of 19 -> 19 of 19) and pinned word for word (M415))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/801671dc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
void func_801671dc(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x234))) + ((0x13 - (arg1 * 5)) * 0x178);
    (*(s32 *)((s8 *)(temp_a0) + (0x130))) = 0x40;
    (*(s32 *)((s8 *)(temp_a0) + (0x134))) = 0x30;
    (*(s32 *)((s8 *)(temp_a0) + (0))) = (s32) ((*(s32 *)((s8 *)(temp_a0) + (0))) | 0x80);
}

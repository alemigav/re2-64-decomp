/* FUN_80162678
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80162678  body 0x80162678..0x801626ab  size 52 B
 * body sha256 8723f38e93d01bd2ef9b91e84a7d95f6982e17e4bdf02a17983d37ddbe5c6782
 * recovered byte-exact (imported: m2c's draft, better than the provider's (10 of 13 -> 13 of 13) and pinned word for word (M415))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80162678.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
void func_80162678(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x2D4))) == 0x8000) {
        if ((*(u8 *)((s8 *)(arg0) + (0x2D9))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (4))) = 0x030A0000;
            return;
        }
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x07000000;
    }
}

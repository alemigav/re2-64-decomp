/* FUN_80163b24
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163b24  body 0x80163b24..0x80163b4f  size 44 B
 * body sha256 f237fe02b75dcb8775df24fafeb6f2e848346b33e3512af4b8da3dc1b81f19dc
 * recovered byte-exact (read from the words (M380): 11 of 11, eleven words, an if/else on bit 6 of the argument: one arm is two stores, the other packs `(v & 0xf) << 16 + 0x02000000` into one word)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80163b24.c
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

void FUN_80163b24(u8 *p, u32 v)
{
    if (!(v & 0x40)) {
        p[5] = v;
        *(u16 *)(p + 6) = 0;
    } else {
        *(u32 *)(p + 4) = ((v & 0x0f) << 16) + 0x02000000;
    }
}

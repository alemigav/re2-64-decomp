/* FUN_801653a0
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801653a0  body 0x801653a0..0x801653fb  size 92 B
 * body sha256 f8d054d9191e4e79b5d67596b5de6c7771be9fa6e711ed0c165882d245bd53b0
 * recovered byte-exact (read from the words (M382): 23 of 23, twenty-three words, a guarded call with two constants, then one unconditional call carrying all three parameters)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/801653a0.c
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

extern void FUN_80165310(u8 *p, u32 a, u32 b);
extern void FUN_80164e88(u8 *p, u8 *q, u32 v);

void FUN_801653a0(u8 *p, u8 *q, u32 v)
{
    if (p[6] == 0) {
        FUN_80165310(p, 2, 6);
    }
    FUN_80164e88(p, q, v);
}

/* FUN_80162f08
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80162f08  body 0x80162f08..0x80162f57  size 80 B
 * body sha256 e57ff6940fef401983ca5ddabda7a3bb880d73e96e8a8468b19a0d3b4cd57bf5
 * recovered byte-exact (masked-loop family: `r[i].v = (r[i].v & 0xff000000) | (hi<<16 | mid<<8 | lo)` on a 376-byte record, 3 copies)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as MASKLOOP_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int u32;

typedef struct { u32 hdr[24]; u32 v; u32 rest[69]; } Rec;

void FUN_maskloop(u32 a0, u32 n, u32 lo, u32 mid, u32 hi)
{
    Rec *r = (Rec *)*(u32 **)(a0 + 0x234);
    u32 i;

    for (i = 0; i < n; i++)
        r[i].v = (r[i].v & 0xff000000u) | (hi << 16 | mid << 8 | lo);
}

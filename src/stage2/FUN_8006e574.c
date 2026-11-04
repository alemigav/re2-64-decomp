/* FUN_8006e574
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e574  body 0x8006e574..0x8006e5cf  size 92 B
 * body sha256 cd7f03bdd32f53ebc67b7975e129ec8ef88136e7506259a453e36d7a26b9f3c3
 * recovered partial: 17 of 23, one register and one schedule slot (p6e574: 17 of 23)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as P6E574_SOURCE
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char  u8;
typedef unsigned int   u32;

struct Ctx {
    u8  pad0[0x1c];
    u8 *f1c;
};

extern u32 D_80115090[];

int FUN_8006e574(struct Ctx *ctx)
{
    u8 *p;
    int a;
    int b;
    int c;

    p = ctx->f1c;
    a = *(u8 *)(p + 1);
    b = *(u8 *)(p + 2);
    c = *(u8 *)(p + 3);
    ctx->f1c += 4;
    return ((*(u32 *)(D_80115090[a] + (b >> 5) * 4) & (0x80000000u >> (b & 31))) != 0) ^ (c == 0);
}

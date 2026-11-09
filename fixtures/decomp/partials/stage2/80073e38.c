typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 D_800c76b0[];
extern u8 D_8010b297[];
extern u8 D_800e8605[];
extern u32 D_801152cc;
extern u8 D_8012bfa8[];
extern u8 D_80131780[];

void f(u8 *ctx)
{
    u8 *t = D_800c76b0;
    u8 v = ctx[1];
    u32 old;

    D_8010b297[0] = v;
    D_800e8605[0] = v;
    old = *(u32 *)(t + 0x18000 + 6716);
    *(u32 *)(t + 0x18000 + 1328) = D_801152cc;
    if (old & 0x40) {
        if (v == 30) {
            *(u16 *)(ctx + 2) = 2;
        }
    }
    if (ctx[7] & 1) {
        *(u8 *)(t + 0x18000 + 6789) = 6;
        *(u8 *)(t + 0x18000 + 6790) = 0;
    } else {
        D_8012bfa8[0] = 2;
        D_80131780[0] = 1;
        *(u32 *)(D_80131780 + 0x1780 + 68) = *(u32 *)(t + 0x18000 + 6752);
        *(u32 *)(t + 0x18000 + 6748) |= 0x8000;
    }
}

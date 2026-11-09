typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 D_800c76b0[];
extern u8 D_800fe288[];
extern u32 D_801152cc;
extern u8 D_8012bfa8[];
extern u8 D_80131780[];

void f(u8 *ctx)
{
    u32 base = (u32)D_800c76b0;
    u32 off = 0x18000;
    u32 off2 = 0x20000;
    u8 v = ctx[1];
    u8 *t;

    *(u8 *)((u32)D_800fe288 + 0x8000 + 20495) = v;
    t = (u8 *)(base + off);
    *(u8 *)(base + off2 + 3925) = v;
    *(u32 *)(t + 1328) = D_801152cc;
    if (*(u32 *)(t + 6716) & 0x40) {
        if (v == 30) {
            *(u16 *)(ctx + 2) = 2;
        }
    }
    if (ctx[7] & 1) {
        *(u8 *)(t + 6789) = 6;
        *(u8 *)(t + 6790) = 0;
    } else {
        D_8012bfa8[0] = 2;
        D_80131780[0] = 1;
        *(u32 *)((u32)D_80131780 + 0x1780 + 68) = *(u32 *)(t + 6752);
        *(u32 *)(t + 6748) |= 0x8000;
    }
}

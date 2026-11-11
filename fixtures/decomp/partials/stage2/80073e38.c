typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 D_800c76b0[]; extern u8 D_800fe288[]; extern u32 D_801152cc;
extern u8 D_8012bfa8[]; extern u8 D_80131780[];
int f(u8 *ctx)
{
    u32 off = 0x18000;
    u32 k8 = 0x8000;
    u32 off2 = 0x20000;
    u32 s1 = (u32)D_800fe288 + k8;
    u8 v = ctx[1];
    u8 *t, *p2;
    u32 old;
    *(u8 *)(s1 + 20495) = v;
    t = (u8 *)((u32)D_800c76b0 + off);
    old = D_801152cc;
    p2 = (u8 *)((u32)D_800c76b0 + off2);
    p2[3925] = v;
    *(u32 *)(t + 1328) = old;
    if (*(u32 *)(t + 6716) & 0x40) { if (v == 30) *(u16 *)(ctx + 2) = 2; }
    if (ctx[7] & 1) {
        u8 *q = (u8 *)((u32)D_800c76b0 + (0x8000 | v));
        q[6789] = 6; q[6790] = 0; return 1;
    }
    D_8012bfa8[0] = 2;
    D_80131780[0] = 1;
    {
        u32 o = 0x18000;
        u8 *w = (u8 *)((u32)D_800c76b0 + o);
        *(u32 *)(D_80131780 + 68) = *(u32 *)(w + 6752);
        *(u32 *)(w + 6748) |= 0x8000;
    }
    return 0;
}

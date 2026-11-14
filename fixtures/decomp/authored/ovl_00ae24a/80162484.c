typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_800c76b0[];
u32 func_80032e74(u32 a0, u32 a1, u32 a2, u32 a3);
u32 func_80059e00(u32 a0, u32 a1);

void FUN_80162484(u32 s1)
{
    u32 base = (u32)D_800c76b0;
    u32 off = 0x18000;
    u8 *s0 = (u8 *)(base + off);
    u32 s2 = *(u32 *)(s1 + 652);
    u32 r = func_80032e74(s1, *(u32 *)(s0 + 6824), *(u32 *)(s0 + 6832), 0x80);
    u32 v0;

    if (*(s32 *)(s1 + 40) < 0x2329)
        return;
    v0 = s2 < 0x1770;
    if (v0 == 0)
        return;
    v0 = r << 16;
    if (v0 != 0)
        return;
    if (*(u8 *)(s0 + 7407) != 0)
        return;
    if (*(s16 *)(s0 + 7282) > 0)
        return;
    v0 = *(u16 *)(s1 + 706);
    v0 &= 4;
    if (v0 != 0)
        return;
    *(u32 *)(s1 + 4) = 0x01040000;
    func_80059e00(0x1f4, 0);
    v0 = *(u8 *)(s0 + 7407);
    v0 |= 0x80;
    *(u8 *)(s0 + 7407) = v0;
    v0 = 4;
    *(u8 *)(s1 + 692) = v0;
    *(u8 *)(s1 + 693) = 0;
    v0 = *(u32 *)(s0 + 6716);
    v0 |= 0x100;
    *(u32 *)(s0 + 6716) = v0;
}

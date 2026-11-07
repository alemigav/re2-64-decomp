typedef unsigned char u8;
typedef unsigned int u32;
extern u8 D_800c76b0[];
extern u32 D_80012884;

void FUN_80004c6c(void)
{
    u8 *t = D_800c76b0;

    D_80012884 = 0;
    *(u32 *)(t + 0x18000 + 6748) = *(u32 *)(t + 0x18000 + 6748) & ~0x20;
}

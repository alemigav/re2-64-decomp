typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u32 FUN_800048b0(u8 *a0)
{
    u32 old = *(u32 *)(a0 + 16);
    u32 d = 0x8000 - old;

    if (d != 0) {
        *(u32 *)(a0 + 16) = 0x8000;
        *(u32 *)(a0 + 80) = *(u32 *)(a0 + 80) + d;
        *(u32 *)(a0 + 12) = *(u32 *)(a0 + 80);
    }

    return d;
}

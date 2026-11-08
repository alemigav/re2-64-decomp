typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 D_80186c94;
extern void FUN_8017bbe8(u32 n);

void FUN_8017b7a8(void)
{
    u8 *p = (u8 *)D_80186c94;
    u32 v = *(u32 *)p + 0x800;

    *(u32 *)(p + 16) = 0;
    *(u32 *)(p + 20) = 0;
    *(u32 *)(p + 12) = 0;
    *(u32 *)(p + 8) = v;
    *(u32 *)(p + 24) = v;
    FUN_8017bbe8(0);
}

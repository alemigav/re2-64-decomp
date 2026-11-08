typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 D_80186c94;

u32 FUN_8017bbb0(u32 a)
{
    u8 *p = (u8 *)D_80186c94;

    return *(u32 *)(p + 12) >> (32 - a);
}

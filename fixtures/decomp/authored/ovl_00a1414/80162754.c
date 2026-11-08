typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_80168b3c(u8 *p, u8 *q);

void FUN_80162754(u8 *p)
{
    FUN_80168b3c(p, (u8 *)(*(u32 *)(p + 564) + 0x1a70));
}

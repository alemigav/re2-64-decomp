typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 D_800138a0;
extern u32 D_800138a4;
extern u32 D_800138a8;
extern u32 D_80013eb4;

void FUN_800013b0(u32 a0)
{
    D_800138a0 = a0;
    D_800138a8 = a0;
    D_80013eb4 = 0;
    D_800138a4 = a0;
}

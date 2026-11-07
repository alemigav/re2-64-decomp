typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_8000305c(u32 a0, u32 a1, u32 a2, u32 a3);

void FUN_8000319c(u32 a0, u32 a1, u32 a2)
{
    FUN_8000305c(a0, 14, a1, a2);
}

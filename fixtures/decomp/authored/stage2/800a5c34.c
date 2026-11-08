typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern void FUN_8000efa0(u32 a, u32 b);

void FUN_800a5c34(u32 a, u32 b)
{
    FUN_8000efa0(a, b << 1);
}

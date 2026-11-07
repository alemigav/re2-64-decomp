typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u8 D_800ebda8[];

s32 FUN_800390b8(u32 i, u8 v)
{
    u8 *b = D_800ebda8;

    b[(i & 0xffff) * 124] = v;
    return 0;
}

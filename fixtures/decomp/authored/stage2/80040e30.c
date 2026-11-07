typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern float D_800f5e30[];

float FUN_80040e30(u32 i)
{
    return D_800f5e30[((i & 0xffff) + 0x400) & 0xfff];
}

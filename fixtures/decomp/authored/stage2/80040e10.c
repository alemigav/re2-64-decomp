typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern u8 D_800f5e30[];

f32 FUN_80040e10(u32 a0)
{
    u8 *b = D_800f5e30;

    return *(f32 *)(b + (a0 & 0xfff) * 4);
}

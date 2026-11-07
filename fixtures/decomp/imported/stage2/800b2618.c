typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
extern u8 D_80147fb0[];

s32 FUN_800b2618(u32 a0)
{
    u8 *b = D_80147fb0;

    return *(s16 *)(b + (a0 & 15) * 2);
}

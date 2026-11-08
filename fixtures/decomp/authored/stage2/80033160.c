typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern s32 FUN_80032d14(s16 a, s16 b, s16 c, s16 d);

s32 FUN_80033160(u8 *a, u8 *b)
{
    s32 d = (s16)FUN_80032d14(*(s16 *)(a + 42), *(s16 *)(a + 50), *(s16 *)(b + 42), *(s16 *)(b + 50));

    return ((*(s16 *)(b + 102) - d + 0x400) & 0xfff) < 0x800;
}

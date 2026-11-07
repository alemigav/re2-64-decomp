typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u32 FUN_8017b8f4(void);

u32 FUN_8017b98c(void)
{
    u32 a = FUN_8017b8f4();
    u32 b = FUN_8017b8f4();

    return (a << 8) | b;
}

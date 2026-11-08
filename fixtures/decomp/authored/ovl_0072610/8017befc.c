typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 FUN_8017bbb0(u32 n);
extern void FUN_8017bd8c(void);

u32 FUN_8017befc(void)
{
    u32 r = FUN_8017bbb0(0x20);

    FUN_8017bd8c();
    return r;
}

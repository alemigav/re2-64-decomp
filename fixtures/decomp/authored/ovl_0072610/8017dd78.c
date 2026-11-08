typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 FUN_8017bbcc(void);
extern void FUN_8017bbe8(u32 n);

void FUN_8017dd78(void)
{
    while (FUN_8017bbcc() != 0) {
        FUN_8017bbe8(8);
    }
}

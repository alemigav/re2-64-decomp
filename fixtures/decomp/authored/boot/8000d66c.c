typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 FUN_8000d9c0(void);
extern void FUN_8000db10(u32 n);

void FUN_8000d66c(void)
{
    while (FUN_8000d9c0() != 0) {
    }
    FUN_8000db10(0x125);
}

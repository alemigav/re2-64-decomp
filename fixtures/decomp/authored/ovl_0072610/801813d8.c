typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 D_80186c98;
extern void FUN_8017ddb0(u32 v);
extern void FUN_8017d0f0(void);

void FUN_801813d8(void)
{
    FUN_8017ddb0(D_80186c98);
    D_80186c98 = D_80186c98 + 1;
    FUN_8017d0f0();
}

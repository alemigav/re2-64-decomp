typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern s32 FUN_80001510(void);

s32 FUN_800022bc(u8 *a, u8 *b)
{
    FUN_80001510();
    (*(s32 (**)(u32, u32))(b + 36))(*(u32 *)(b + 40), *(u32 *)(a + 36));
    (*(s32 (**)(u32, u8 *))(b + 36))(*(u32 *)(b + 40), a);
    return 0;
}

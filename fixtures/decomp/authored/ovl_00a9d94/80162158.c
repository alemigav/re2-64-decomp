typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_8016ba54(void);

void FUN_80162158(u8 *ctx)
{
    if (*(u16 *)(ctx + 426) & 1) {
        FUN_8016ba54();
    }
}

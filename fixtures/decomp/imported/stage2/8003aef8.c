typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
extern u8 *D_800ebb94;

void FUN_8003aef8(void)
{
    u8 *p = D_800ebb94;

    *(u16 *)(p + 4) = *(u16 *)(p + 4) + 0x100;
}

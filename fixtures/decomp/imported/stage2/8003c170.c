typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
void FUN_8003c170(void)
{
    u8 *p = *(u8 **)0x800ebb94;

    p[8] = 0;
    *(u16 *)(p + 12) = 0;
    p[3] = 0;
}

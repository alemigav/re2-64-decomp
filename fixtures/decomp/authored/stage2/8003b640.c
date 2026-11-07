typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u16 *D_800ebb94;

void FUN_8003b640(void)
{
    u16 *p = D_800ebb94;

    p[2] += p[9];
    p[3] += p[10];
}

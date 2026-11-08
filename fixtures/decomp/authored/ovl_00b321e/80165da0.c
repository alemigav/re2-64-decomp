typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80165ea0(u8 *p, u8 *q);
extern void FUN_80165bd0(u8 *p, u32 a, s16 b, u32 c);

void FUN_80165da0(u8 *p, u8 *q)
{
    FUN_80165ea0(p, q);
    FUN_80165bd0(p, 3, *(s16 *)(q + 2), 0);
    FUN_80165bd0(p, 4, *(s16 *)(q + 4), 0);
}

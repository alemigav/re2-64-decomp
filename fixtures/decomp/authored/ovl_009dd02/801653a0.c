typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80165310(u8 *p, u32 a, u32 b);
extern void FUN_80164e88(u8 *p, u8 *q, u32 v);

void FUN_801653a0(u8 *p, u8 *q, u32 v)
{
    if (p[6] == 0) {
        FUN_80165310(p, 2, 6);
    }
    FUN_80164e88(p, q, v);
}

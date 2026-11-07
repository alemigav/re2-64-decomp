typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern s16 D_80139a80[];

void FUN_8004343c(s32 *p)
{
    p[0] = D_80139a80[0];
    p[1] = D_80139a80[1];
    p[2] = D_80139a80[2];
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern u32 D_80166db8[];
extern void FUN_801664d8(u8 *p);
extern void FUN_80166980(u8 *p, u32 a, u32 b);

void FUN_80162dd4(u8 *p)
{
    (*(void (**)(u8 *))(&D_80166db8[p[6]]))(p);
    FUN_801664d8(p);
    FUN_80166980(p, 4, 0);
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80162e60(u8 *p);
extern void FUN_80163094(u8 *p);

void FUN_80162e28(u8 *p)
{
    if (p[6] == 0) {
        FUN_80162e60(p);
    } else {
        FUN_80163094(p);
    }
}

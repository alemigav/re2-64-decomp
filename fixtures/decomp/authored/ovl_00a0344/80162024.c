typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_8016205c(u8 *p);
extern void FUN_80162064(u8 *p);

void FUN_80162024(u8 *p)
{
    if (p[427] == 0) {
        FUN_8016205c(p);
    } else {
        FUN_80162064(p);
    }
}

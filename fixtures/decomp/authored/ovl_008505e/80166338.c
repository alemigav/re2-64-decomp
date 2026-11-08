typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_80166370(u8 *p);

void FUN_80166338(u8 *p)
{
    if (p[5] == 0) {
        p[5] = 1;
        *(u32 *)p |= 2;
    }
    FUN_80166370(p);
}

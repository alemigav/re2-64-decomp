typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

void FUN_80163b24(u8 *p, u32 v)
{
    if (!(v & 0x40)) {
        p[5] = v;
        *(u16 *)(p + 6) = 0;
    } else {
        *(u32 *)(p + 4) = ((v & 0x0f) << 16) + 0x02000000;
    }
}

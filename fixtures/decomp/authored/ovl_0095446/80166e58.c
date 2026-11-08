typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;

extern void FUN_801626f4(u8 *p);
extern void FUN_80166e9c(u8 *p);

void FUN_80166e58(u8 *p)
{
    if (*(u16 *)(p + 698) & 0x2000) {
        u32 v = *(u32 *)(p + 664);

        *(u16 *)(p + 498) = 0;
        *(u32 *)(p + 4) = v;
        FUN_801626f4(p);
    } else {
        FUN_80166e9c(p);
    }
}

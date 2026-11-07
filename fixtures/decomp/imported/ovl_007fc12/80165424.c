typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
void FUN_80165424(u8 *a0)
{
    if (a0[6] == 0) {
        a0[6] = 1;
        *(u32 *)(a0 + 488) = 0x17000000;
    }
}

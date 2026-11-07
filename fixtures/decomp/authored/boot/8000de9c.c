typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u8 *FUN_8000de9c(u8 *a0, u8 *a1, u32 a2)
{
    u8 *p = a0;

    if (a2 != 0) {
        do {
            *p = *a1;
            a1++;
            a2--;
            p++;
        } while (a2 != 0);
    }

    return a0;
}

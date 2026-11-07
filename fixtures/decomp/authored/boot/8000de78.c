typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
u32 FUN_8000de78(u8 *a0)
{
    u8 *p = a0;

    if (*p != 0) {
        do {
            p++;
        } while (*p != 0);
    }

    return p - a0;
}

typedef unsigned char u8;
typedef unsigned int u32;

u32 f(u32 want)
{
    u32 found = 0xffff;
    u32 i;

    if (*(u8 *)0x80136d80 == 0) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (*(u8 *)(0x80168b20 + i * 0x1228 + 4608) != 0) {
            if (*(u32 *)(0x80168b20 + i * 0x1228 + 4644) == want) {
                found = i;
                break;
            }
        }
    }
    if (found != 0xffff) {
        return *(u8 *)(0x80168b20 + found * 0x1228 + 4608) != 0;
    }
    return 0;
}

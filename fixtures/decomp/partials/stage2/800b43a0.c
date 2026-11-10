typedef unsigned char u8;
typedef unsigned int u32;

u32 f(u32 want)
{
    u32 i;
    u32 found;

    if (*(u8 *)0x80136d80 != 0) {
        found = want;
        for (i = 0; i < 2; i++) {
            if (*(u8 *)(0x80168b20 + i * 0x1228 + 4608) != 0) {
                if (*(u32 *)(0x80168b20 + i * 0x1228 + 4644) == found) {
                    found = i;
                    break;
                }
            }
        }
        if (i == 2) {
            found = 0xffff;
        }
        if (found != 0xffff) {
            return *(u8 *)(0x80168b20 + found * 0x1228 + 4608) != 0;
        }
        return 0;
    }
    return 0;
}

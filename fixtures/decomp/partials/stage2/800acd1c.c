typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 D_801521e0;
extern u8 D_801521f0[];
u32 func_800a5678(u32 a0);
void func_800a56c0(void);

u32 FUN_800acd1c(u32 key)
{
    s32 count;
    s32 n;
    u32 i;
    u32 k;
    u32 key16;
    u8 *tab;
    u8 *p;
    u8 *q;

    func_800a5678(key);
    count = D_801521e0;
    i = 0;
    if (count > 0) {
        key16 = key & 0xffff;
        n = count;
        tab = D_801521f0;
        while (i < (u32)n) {
            if (*(u16 *)(tab + 4) == key16)
                break;
            i++;
            tab += 8;
        }
    }
    if ((s32)i == count) {
        func_800a56c0();
        return 0;
    }
    tab = D_801521f0 + i * 8;
    *(u16 *)(tab + 6) = *(u16 *)(tab + 6) - 1;
    if (*(u16 *)(tab + 6) != 0) {
        func_800a56c0();
        return 1;
    }
    p = D_801521f0 + (i + 1) * 8;
    q = D_801521f0 + i * 8;
    for (k = i + 1; (s32)k < count; k++) {
        *(u32 *)q = *(u32 *)p;
        *(u32 *)(q + 4) = *(u32 *)(p + 4);
        p += 8;
        q += 8;
    }
    D_801521e0 = count - 1;
    func_800a56c0();
    return 1;
}

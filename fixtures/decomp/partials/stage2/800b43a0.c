typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4608];
    u8 slot;
    u8 gap[35];
    u32 key;
} Rec;

extern Rec D_80158b20[];
extern u8 D_80136d80[];

u32 f(u32 want)
{
    u32 i;
    u32 found;
    Rec *p;

    if (D_80136d80[0] != 0) {
        found = want;
        i = 0;
        p = D_80158b20;
        for (; i < 2; i++, p++) {
            if (p->slot == 0)
                continue;
            if (p->key == want) {
                found = i;
                break;
            }
        }
        if (i == 2)
            found = 0xffff;
        if (found != 0xffff)
            return D_80158b20[found].slot != 0;
        return 0;
    }
    return 0;

}

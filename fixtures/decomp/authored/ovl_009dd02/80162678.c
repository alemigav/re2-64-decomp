typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
void func_80162678(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x2D4))) == 0x8000) {
        if ((*(u8 *)((s8 *)(arg0) + (0x2D9))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (4))) = 0x030A0000;
            return;
        }
        (*(s32 *)((s8 *)(arg0) + (4))) = 0x07000000;
    }
}

typedef signed char s8; typedef unsigned char u8; typedef signed short s16;
typedef unsigned short u16; typedef signed int s32; typedef unsigned int u32;
typedef signed long long s64; typedef unsigned long long u64;
void func_801671dc(void *arg0, s32 arg1) {
    void *temp_a0;

    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x234))) + ((0x13 - (arg1 * 5)) * 0x178);
    (*(s32 *)((s8 *)(temp_a0) + (0x130))) = 0x40;
    (*(s32 *)((s8 *)(temp_a0) + (0x134))) = 0x30;
    (*(s32 *)((s8 *)(temp_a0) + (0))) = (s32) ((*(s32 *)((s8 *)(temp_a0) + (0))) | 0x80);
}

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;

void func_8017022C_overlay_054(void *arg0) {
    u8 var_a1;
    void *temp_a2;

    temp_a2 = arg0 + 0x2B4;
    var_a1 = (*(u8 *)((s8 *)(temp_a2) + (0x26)));
    if ((*(u8 *)((s8 *)(arg0) + (8))) != 0x2E) {
        var_a1 += 8;
    }
    (*(u8 *)((s8 *)(temp_a2) + (0xC))) = var_a1;
    (*(s8 *)((s8 *)(temp_a2) + (0xB))) = 0x5A;
    (*(s32 *)((s8 *)(arg0) + (0))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0))) & ~4);
    (*(s8 *)((s8 *)(temp_a2) + (2))) = 0;
    (*(s16 *)((s8 *)(arg0) + (6))) = 0x100;
    (*(s32 *)((s8 *)(arg0) + (0x1E8))) = (s32) (((*(u8 *)((s8 *)(arg0) + (0x2CD))) * 0x0D000000) + 0x3F00);
    if ((*(u8 *)((s8 *)(temp_a2) + (4))) == 0) {
        (*(s16 *)((s8 *)(arg0) + (6))) = 0x200;
        (*(s8 *)((s8 *)(temp_a2) + (0x12))) = 1;
        (*(s8 *)((s8 *)(temp_a2) + (0x13))) = 0;
        (*(s8 *)((s8 *)(temp_a2) + (0x14))) = 0x20;
    }
}
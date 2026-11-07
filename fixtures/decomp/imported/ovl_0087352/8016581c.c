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

void func_8016579C_ovl_13(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (6))) == 0) {
        (*(u8 *)((s8 *)(arg0) + (0x26F))) = 0x80;
        (*(s32 *)((s8 *)(arg0) + (0))) |= 2;
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x208)))) + (0xE))) = 0;
        (*(u8 *)((s8 *)(arg0) + (6))) = 1U;
    }
}
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

void func_80163AA4_overlay_027(void *arg0, s8 arg1) {
    if (!(arg1 & 0x40)) {
        (*(s8 *)((s8 *)(arg0) + (5))) = arg1;
        (*(s16 *)((s8 *)(arg0) + (6))) = 0;
        return;
    }
    (*(s32 *)((s8 *)(arg0) + (4))) = (s32) (((arg1 & 0xF) << 0x10) + 0x02000000);
}
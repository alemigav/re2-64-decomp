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
extern volatile u32 D_8016722C_ovl_26[];
void func_80163668_ovl_26(void *arg0) {
    volatile u32 *base = D_8016722C_ovl_26;
    u32 idx = *((u8 *)arg0 + 6);
    ((void (*)(void))base[idx])();
}
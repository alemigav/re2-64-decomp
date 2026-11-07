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
extern volatile u32 func_80165478_ovl_35[];
void func_801649A8_ovl_19(void *arg0) { volatile u32 *table = func_80165478_ovl_35 + 2; s32 i = *((u8 *)arg0 + 5); i -= 1; ((void (*)(void))table[i])(); }
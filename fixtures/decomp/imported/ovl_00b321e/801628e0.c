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
extern volatile u32 D_80166674_ovl_35[];
void func_80162860_ovl_35(void *arg0) { void (*fn)(void) = (void (*)(void))D_80166674_ovl_35[((u8 *)arg0)[6]]; fn(); }
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
s32 func_8017BB30_ovl_02(s32 arg0);
void func_8017BB68_ovl_02(s32 arg0);
extern u8 *D_80186C14_ovl_02;

void func_8017D194_ovl_02(void) {
    s32 v;

    v = *(s32 *)(D_80186C14_ovl_02 + 0x10);
    v &= 7;
    for (;;) {
        func_8017BB68_ovl_02(v);
        if (func_8017BB30_ovl_02(0x18) == 1) {
            break;
        }
        v = 8;
    }
}
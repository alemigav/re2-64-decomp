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

M2C_UNK func_8017D070_overlay_002();                
M2C_UNK func_8017DD30_overlay_002(s32);             
extern s32 D_80186C18_overlay_002;

void func_80181358_ovl_02(void) {
    func_8017DD30_overlay_002(D_80186C18_overlay_002);
    D_80186C18_overlay_002 += 1;
    func_8017D070_overlay_002();
}
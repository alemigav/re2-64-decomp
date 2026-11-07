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


extern int (*D_80167D64_overlay_030[])();
M2C_UNK func_80167B9C_overlay_030(void *);          

void func_80162094_overlay_030(void *arg0) {
    void *temp_s1;

    temp_s1 = arg0 + 0x2B4;
    D_80167D64_overlay_030[(*(u8 *)((s8 *)(arg0) + (5)))]();
    (*(u8 *)((s8 *)(temp_s1) + (6))) = (u8) (*(u8 *)((s8 *)(arg0) + (5)));
    (*(u8 *)((s8 *)(temp_s1) + (7))) = (u8) (*(u8 *)((s8 *)(arg0) + (6)));
    (*(u8 *)((s8 *)(temp_s1) + (8))) = (u8) (*(u8 *)((s8 *)(arg0) + (7)));
    (*(u16 *)((s8 *)(temp_s1) + (0x1E))) = (u16) (*(u16 *)((s8 *)(arg0) + (0x1E0)));
    (*(u16 *)((s8 *)(temp_s1) + (0x20))) = (u16) (*(u16 *)((s8 *)(arg0) + (0x1E2)));
    (*(u16 *)((s8 *)(temp_s1) + (0x22))) = (u16) (*(u16 *)((s8 *)(arg0) + (0x1E4)));
    func_80167B9C_overlay_030(arg0);
}
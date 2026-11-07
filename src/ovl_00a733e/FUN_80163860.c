/* FUN_80163860
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163860  body 0x80163860..0x80163893  size 52 B
 * body sha256 de58eae2e00936d7227fdc00c3f274c512df6276063daa35117678ff56ad126c
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_801637E0_ovl_30, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a733e/80163860.c
 * extents and pins: fixtures/decomp/recovered.json
 */
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


extern int (*D_80167DA8_overlay_030[])();
void func_801637E0_ovl_30(void *arg0) {
    D_80167DA8_overlay_030[(*(u8 *)((s8 *)(arg0) + (6)))]();
}

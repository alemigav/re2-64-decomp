/* FUN_801628e0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801628e0  body 0x801628e0..0x80162913  size 52 B
 * body sha256 28e58598fbc405e0096c5f3f7dc47b4ee24581ded9f1920af2774e9fd0977438
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80162860_ovl_35, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b321e/801628e0.c
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
extern volatile u32 D_80166674_ovl_35[];
void func_80162860_ovl_35(void *arg0) { void (*fn)(void) = (void (*)(void))D_80166674_ovl_35[((u8 *)arg0)[6]]; fn(); }

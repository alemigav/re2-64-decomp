/* FUN_80162dd4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80162dd4  body 0x80162dd4..0x80162e2b  size 88 B
 * body sha256 02a9b266c7f91d239abf5e036085fbae067ff6a41fb5254938d107c225748c0f
 * recovered byte-exact (import by content alignment: 22 of 22 words at our own address (func_80162D54_ovl_12, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_008505e/80162dd4.c
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


extern int (*D_80166D38_overlay_012[])();
M2C_UNK func_80166458_overlay_012(void *);          
M2C_UNK func_80166900_overlay_012(void *, M2C_UNK, M2C_UNK); 

void func_80162D54_ovl_12(void *arg0) {
    D_80166D38_overlay_012[(*(u8 *)((s8 *)(arg0) + (6)))]();
    func_80166458_overlay_012(arg0);
    func_80166900_overlay_012(arg0, 4, 0);
}

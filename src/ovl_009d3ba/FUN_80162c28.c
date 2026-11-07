/* FUN_80162c28
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162c28  body 0x80162c28..0x80162c5b  size 52 B
 * body sha256 8ab31623ac0b4806bb64ef0240c749024a3062361f6634e2d81b645442a42cc0
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80162BA8_ovl_25, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009d3ba/80162c28.c
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


extern int (*D_8016307C_overlay_025[])();
void func_80162BA8_ovl_25(void *arg0) {
    D_8016307C_overlay_025[(*(u8 *)((s8 *)(arg0) + (0x26E)))]();
}

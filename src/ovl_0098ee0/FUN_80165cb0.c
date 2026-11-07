/* FUN_80165cb0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165cb0  body 0x80165cb0..0x80165d23  size 116 B
 * body sha256 ab84d5d2fe87a1ee3274425de6879c558327ae18660d3e48529c9317c2d1a782
 * recovered byte-exact (import by content alignment: 29 of 29 words at our own address (func_80165C30_ovl_22, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0098ee0/80165cb0.c
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
typedef struct
{
  u8 x[0x300];
} Obj;
extern void func_80165C28_ovl_22(Obj *);
typedef void (*Fn)(Obj *, s32, s32);
extern volatile Fn D_80166870_ovl_22[];
void func_80165C30_ovl_22(Obj *a, s32 b, s32 c)
{
  s32 ff = 0xFF;
  if (a->x[5] != ff)
  {
    a->x[5] = ff;
    func_80165C28_ovl_22(a);
  }
  ff = a->x[0x26E];
  D_80166870_ovl_22[ff](a, b, c);
}

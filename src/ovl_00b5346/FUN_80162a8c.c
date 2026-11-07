/* FUN_80162a8c
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x80162a8c  body 0x80162a8c..0x80162ad3  size 72 B
 * body sha256 3c2ed2047272ce6c3f07be62fd4905c7cccd804d397de1aec180ee52b4da003c
 * recovered byte-exact (import by content alignment: 18 of 18 words at our own address (func_80162A0C_ovl_36, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00b5346/80162a8c.c
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
void func_80162888_ovl_36(void *);
extern volatile u32 D_80162FFC_ovl_36[];
void func_80162A0C_ovl_36(void *arg0)
{
  void *p = arg0;
  volatile u32 *base = D_80162FFC_ovl_36;
  u32 i = *((u8 *)p + 6);
  ((void (*)(void *))base[i])(p);
  func_80162888_ovl_36(p);
}

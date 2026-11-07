/* FUN_80166584
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80166584  body 0x80166584..0x801665b7  size 52 B
 * body sha256 67c40f65a53fdc92249317d18e3178cc2324cfbfc52d84742557cd90deeb314a
 * recovered byte-exact (import by content alignment: 13 of 13 words at our own address (func_80166504_ovl_26, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_009dd02/80166584.c
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
extern volatile u32 D_80167328_ovl_26[];
void func_80166504_ovl_26(void *arg0) {
  volatile u32 *p = D_80167328_ovl_26;
  s32 idx = ((u8 *)arg0)[0x2C6];
  void (*fn)(void *, u8 *) = (void (*)(void *, u8 *))p[idx];
  fn(arg0, (u8 *)arg0 + 0x2B4);
}

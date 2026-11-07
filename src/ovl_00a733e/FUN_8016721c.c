/* FUN_8016721c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x8016721c  body 0x8016721c..0x8016726b  size 80 B
 * body sha256 cf2f105dbf300dac4c7440db51eec938d38bcf816fe32b1f68b8433bd4311f54
 * recovered byte-exact (import by content alignment: 20 of 20 words at our own address (func_8016719C_ovl_30, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_00a733e/8016721c.c
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
extern volatile s8 D_80167CEB_ovl_30;
s32 func_8016719C_ovl_30(s32 arg0)
{
  s8 x = D_80167CEB_ovl_30 + arg0;
  D_80167CEB_ovl_30 = x;
  if (x >= 9)
  {
    D_80167CEB_ovl_30 = 8;
    return 1;
  }
  if (x < (-8))
  {
    x = 8;
    D_80167CEB_ovl_30 = -x;
    return -1;
  }
  return 0;
}

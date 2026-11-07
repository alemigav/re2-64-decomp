/* FUN_8017b50c
 * image   ovl_0072610 (ovl), base 0x8017b410
 * address 0x8017b50c  body 0x8017b50c..0x8017b597  size 140 B
 * body sha256 d33490f6b26aa184c593712b62dd35992e4eb470f6ddec55fde7d5eda89258ff
 * recovered byte-exact (import by content alignment: 35 of 35 words at our own address (func_8017B48C_ovl_02, delta +128))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/imported/ovl_0072610/8017b50c.c
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
s32 func_8017B3CC_overlay_002();
extern s32 D_80184AA4_overlay_002;
extern s32 D_80184AA8_overlay_002;
extern u32 D_80184AAC_overlay_002;
u32 func_8017B48C_ovl_02(s32 arg0, s32 *arg1, u32 arg2)
{
  u32 var_s0;
  u32 new_var;
  var_s0 = arg2;
  if (D_80184AA8_overlay_002 == 0)
  {
    func_8017B3CC_overlay_002();
  }
  new_var = D_80184AA4_overlay_002 + 0x1000;
  *arg1 = new_var - D_80184AA8_overlay_002;
  D_80184AA8_overlay_002 -= var_s0;
  new_var = var_s0;
  if (((u32) D_80184AAC_overlay_002) < new_var)
  {
    var_s0 = D_80184AAC_overlay_002;
  }
  D_80184AAC_overlay_002 -= var_s0;
  return (int) var_s0;
}

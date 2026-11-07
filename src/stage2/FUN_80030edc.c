/* FUN_80030edc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030edc  body 0x80030edc..0x80030f17  size 60 B
 * body sha256 1f0515842c21f01cd7eb3b9d87e3348494b4957c0a75da24bc3b0212eebbd905
 * recovered byte-exact (import by content alignment: 15 of 15 words at our own address (func_80030F0C_ovl_01))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_80030EDC_SOURCE
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
s32 func_80030F0C_ovl_01(s32 arg0, s32 arg1)
{
  s32 temp_a0;
  int new_var;
  new_var = 1;
  temp_a0 = (arg0 - new_var) + arg1;
  return temp_a0 - (temp_a0 % arg1);
}

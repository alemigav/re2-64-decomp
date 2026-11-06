/* FUN_8000e800
 * image   boot (boot), base 0x80000480
 * address 0x8000e800  body 0x8000e800..0x8000e853  size 84 B
 * body sha256 98cb6ae021b8cb8122d396485a55dcd24998c5118a69d52c016a4d4c9695213f
 * recovered byte-exact (import: 21 of 21 words, from the decompdecomp corpus and verified against this cartridge)
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in tools/compile_probe.py as S_8000E800_SOURCE
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

s32 func_8000E860(s32);

s32 func_8000E800(s32 arg0)
{
  if ((u32) (arg0 - 0x80000000) > 0x1FFFFFFFU)
  {
    if ((u32) (arg0 + 0x60000000) > 0x1FFFFFFFU)
    {
      return func_8000E860(arg0);
    }
    return arg0 & 0x1FFFFFFF;
  }
  return arg0 & 0x1FFFFFFF;
}

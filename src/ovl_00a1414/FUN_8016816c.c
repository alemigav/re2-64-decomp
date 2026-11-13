/* FUN_8016816c
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x8016816c  body 0x8016816c..0x8016819f  size 52 B
 * body sha256 398761f61e2b387b3dd09e784049516622050ac2707cf7649aff87f9dcdc85d3
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a1414/8016816c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80169068;












void FUN_8016816c(int param_1)

{
  (*(code *)(&PTR_FUN_80169068)[*(byte *)(param_1 + 5)])();
  return;
}

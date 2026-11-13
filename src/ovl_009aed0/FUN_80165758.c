/* FUN_80165758
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80165758  body 0x80165758..0x8016578b  size 52 B
 * body sha256 50274c9a46101bca419618dbb4c112ecd5cd560e2d2214fbc6b2a4852d16d89f
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009aed0/80165758.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_8016663c;












void FUN_80165758(int param_1)

{
  (*(code *)(&PTR_FUN_8016663c)[*(byte *)(param_1 + 5)])();
  return;
}

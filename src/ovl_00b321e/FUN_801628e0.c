/* FUN_801628e0
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801628e0  body 0x801628e0..0x80162913  size 52 B
 * body sha256 f03e74aac378291a0eb64ad1bf740082035c7c3cceba01807cd2d6082c9eb633
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/801628e0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801666f4;












void FUN_801628e0(int param_1)

{
  (*(code *)(&PTR_FUN_801666f4)[*(byte *)(param_1 + 6)])();
  return;
}

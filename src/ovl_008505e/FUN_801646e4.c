/* FUN_801646e4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801646e4  body 0x801646e4..0x8016472b  size 72 B
 * body sha256 932be94037f3b0da7bb81703a3d8989b3ea79a7b34fe4adbb803748aee5e1cc2
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801646e4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80166de4;












void FUN_801646e4(int param_1)

{
  (*(code *)(&PTR_FUN_80166de4)[*(byte *)(param_1 + 6)])();
  FUN_801664d8(param_1);
  return;
}

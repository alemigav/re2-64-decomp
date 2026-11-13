/* FUN_80162c28
 * image   ovl_009d3ba (ovl), base 0x80161cf0
 * address 0x80162c28  body 0x80162c28..0x80162c5b  size 52 B
 * body sha256 a38379ac81727e1c29fe5f7487e4c729e8be3351fff2e2f63b81df39cf4bee1b
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009d3ba/80162c28.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_801630fc;












void FUN_80162c28(int param_1)

{
  (*(code *)(&PTR_FUN_801630fc)[*(byte *)(param_1 + 0x26e)])();
  return;
}

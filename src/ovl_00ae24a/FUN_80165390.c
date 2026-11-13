/* FUN_80165390
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x80165390  body 0x80165390..0x801653c3  size 52 B
 * body sha256 92e42533abda72f0ee0bdadd579edc8de598d2836df9121a63de012fd5b71b19
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00ae24a/80165390.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167030;












void FUN_80165390(int param_1)

{
  (*(code *)(&PTR_FUN_80167030)[*(byte *)(param_1 + 5)])();
  return;
}

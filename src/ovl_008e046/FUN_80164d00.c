/* FUN_80164d00
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164d00  body 0x80164d00..0x80164d33  size 52 B
 * body sha256 74ce942b2bfa0744830e1fe9a50a6949b44a5a758fd2ecaad31803cead084cf0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008e046/80164d00.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167498;












void FUN_80164d00(int param_1)

{
  (*(code *)(&PTR_FUN_80167498)[*(byte *)(param_1 + 5)])();
  return;
}

/* FUN_80162ac4
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162ac4  body 0x80162ac4..0x80162af7  size 52 B
 * body sha256 ddadbef4e4e15978525e1b595823e6c3924c060c617bf76f612bd324dff73d73
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80162ac4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80163db0;












void FUN_80162ac4(int param_1)

{
  (*(code *)(&PTR_FUN_80163db0)[*(byte *)(param_1 + 5)])();
  return;
}

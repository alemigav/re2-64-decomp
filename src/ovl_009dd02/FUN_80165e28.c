/* FUN_80165e28
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165e28  body 0x80165e28..0x80165e5b  size 52 B
 * body sha256 72c15cd5de72ede9f6ec12017b22278ccd3428a7aad81baf8bf35097fd51a54c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80165e28.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167390;












void FUN_80165e28(int param_1)

{
  (*(code *)(&PTR_FUN_80167390)[*(byte *)(param_1 + 5)])();
  return;
}

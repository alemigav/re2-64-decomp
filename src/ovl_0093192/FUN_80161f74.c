/* FUN_80161f74
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80161f74  body 0x80161f74..0x80161fa7  size 52 B
 * body sha256 5af366f093c353806769e7344b8c97402b586bacbf4c71b2f7e0e5676628b96c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0093192/80161f74.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80162d38;












void FUN_80161f74(int param_1)

{
  (*(code *)(&PTR_FUN_80162d38)[*(byte *)(param_1 + 5)])();
  return;
}

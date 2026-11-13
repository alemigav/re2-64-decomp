/* FUN_8016834c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016834c  body 0x8016834c..0x80168383  size 56 B
 * body sha256 ca0d29e2bfc991d9245ce4236faf7061f74b4050d2468ccc7bc12c6019a57167
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016834c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_8016c4f8;












void FUN_8016834c(int param_1)

{
  (*(code *)(&PTR_FUN_8016c4f8)[*(ushort *)(param_1 + 0x1aa) & 1])();
  return;
}

/* FUN_80163860
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163860  body 0x80163860..0x80163893  size 52 B
 * body sha256 db4efedd02cdd57f1444dc9565a2959377f0143fadfb6d470c11076b790bd00a
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a733e/80163860.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char byte;
typedef void code();
extern unsigned int PTR_FUN_80167e28;












void FUN_80163860(int param_1)

{
  (*(code *)(&PTR_FUN_80167e28)[*(byte *)(param_1 + 6)])();
  return;
}

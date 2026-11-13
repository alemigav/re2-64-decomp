/* FUN_80161ebc
 * image   ovl_00b2d7a (ovl), base 0x80161cf0
 * address 0x80161ebc  body 0x80161ebc..0x80161ef3  size 56 B
 * body sha256 9ef82ef8e1971bfa0415d295010de7b6585a50c5362176bcc797d9d27a711d6c
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b2d7a/80161ebc.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80162610;












void FUN_80161ebc(int param_1)

{
  (*(code *)(&PTR_FUN_80162610)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}

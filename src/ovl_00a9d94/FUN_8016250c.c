/* FUN_8016250c
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016250c  body 0x8016250c..0x80162567  size 92 B
 * body sha256 766d264816acdee65a8cd1680cde061c7078b84f270d676ea8aaab063ed67bad
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a9d94/8016250c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_8016c400;












void FUN_8016250c(int param_1)

{
  (*(code *)(&PTR_FUN_8016c400)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  if ((*(ushort *)(param_1 + 0x2b6) & 0x180) == 0x100) {
    *(undefined4 *)(param_1 + 4) = 0x3000000;
  }
  return;
}

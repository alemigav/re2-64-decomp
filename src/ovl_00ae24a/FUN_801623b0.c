/* FUN_801623b0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801623b0  body 0x801623b0..0x801623e7  size 56 B
 * body sha256 7ca7ecd410ed7f42647b478bb37d325bf1861cce92ccdc7edf52ad88c38501c0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00ae24a/801623b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80166f8c;












void FUN_801623b0(int param_1)

{
  (*(code *)(&PTR_FUN_80166f8c)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}

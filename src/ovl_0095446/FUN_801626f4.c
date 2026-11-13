/* FUN_801626f4
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x801626f4  body 0x801626f4..0x8016272b  size 56 B
 * body sha256 4d0e8afb062914b390b296d7823fd03856dbb36ca127e8f8522772544d37bbc4
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0095446/801626f4.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_80167fcc;












void FUN_801626f4(int param_1)

{
  (*(code *)(&PTR_FUN_80167fcc)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}

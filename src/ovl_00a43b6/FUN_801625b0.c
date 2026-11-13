/* FUN_801625b0
 * image   ovl_00a43b6 (ovl), base 0x80161cf0
 * address 0x801625b0  body 0x801625b0..0x801625e7  size 56 B
 * body sha256 07edf2d92ea2f11a28071d7500e93dc4a94204d39753402ffadfdfd55d892376
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a43b6/801625b0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned short ushort;
typedef void code();
extern unsigned int PTR_FUN_801697ec;












void FUN_801625b0(int param_1)

{
  (*(code *)(&PTR_FUN_801697ec)[*(ushort *)(param_1 + 0x1aa) & 0x3f])();
  return;
}

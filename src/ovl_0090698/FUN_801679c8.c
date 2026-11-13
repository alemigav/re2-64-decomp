/* FUN_801679c8
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801679c8  body 0x801679c8..0x801679f3  size 44 B
 * body sha256 324dcf6ddffcd45a11ff03da6235c11626e4ca9bf494b601db3f4c811b57dce0
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/801679c8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_801679c8(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = 0;
  do {
    uVar2 = uVar2 + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x234) + iVar1 + 0x60) = param_2;
    iVar1 = iVar1 + 0x178;
  } while (uVar2 < 0x14);
  return;
}

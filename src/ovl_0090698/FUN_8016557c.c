/* FUN_8016557c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016557c  body 0x8016557c..0x801655df  size 100 B
 * body sha256 61284cb862a2314c2b616fbb00ad88241f35bcea8536afbf540457c16fc194db
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/8016557c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_8016557c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0x2d7) = 0x14;
  FUN_8016703c(param_1,0,10);
  *(undefined1 *)(param_1 + 5) = 7;
  FUN_80164a78(param_1,param_2,param_3);
  return;
}

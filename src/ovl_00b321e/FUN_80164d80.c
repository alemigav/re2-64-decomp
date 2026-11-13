/* FUN_80164d80
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80164d80  body 0x80164d80..0x80164dbb  size 60 B
 * body sha256 4fa871438e3e9233e8b7b147883ebb2f189df77741c927d1b20d64a628cf937d
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/80164d80.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164d80(undefined4 param_1)

{
  uint uVar1;
  
  FUN_80163620();
  uVar1 = func_0x80033604();
  FUN_801663a4(param_1,3,uVar1 & 7);
  return;
}

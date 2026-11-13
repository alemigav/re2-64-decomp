/* FUN_80164e1c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164e1c  body 0x80164e1c..0x80164e87  size 108 B
 * body sha256 b5edcdac82b879bc7e3f01eea24f4f619819183d033da649511023583bc4e03d
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_0090698/80164e1c.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80164e1c(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  if (*(unsigned char *)(param_1 + 6) == '\0') {
    uVar1 = func_0x80033604();
    FUN_80167688(param_1,0x2004,(uVar1 & 1) + 1);
  }
  FUN_80164aac(param_1,param_2,param_3);
  return;
}

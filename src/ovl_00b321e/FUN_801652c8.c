/* FUN_801652c8
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x801652c8  body 0x801652c8..0x80165327  size 96 B
 * body sha256 99b1d105d9c1590146793f56e3a412a8e046dc54dd0c4a8ef1aeaa8898cf20b0
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00b321e/801652c8.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;












void FUN_801652c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000f00;
    *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  }
  return;
}

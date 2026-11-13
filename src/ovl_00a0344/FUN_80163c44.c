/* FUN_80163c44
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80163c44  body 0x80163c44..0x80163c8f  size 76 B
 * body sha256 b018eb81f10d5827fddf9350ba1b45b42cafde1167468db36ee8cb30ee6d7045
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_00a0344/80163c44.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned int undefined4;
extern unsigned int DAT_80163e68;
extern unsigned int DAT_80163ed4;












void FUN_80163c44(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80163e68,param_2);
  func_0x80036008(param_1,*(undefined4 *)(param_1 + 0x234),&DAT_80163ed4,uVar1);
  return;
}

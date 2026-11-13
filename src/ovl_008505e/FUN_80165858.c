/* FUN_80165858
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165858  body 0x80165858..0x801658eb  size 148 B
 * body sha256 e33f276f74d761a90609b6da1099a0975d49f3794edeff049c399e1283471b7e
 * recovered byte-exact (imported: the whole body matches by offset and content (M410, banked from the distance map))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/80165858.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned int uint;












void FUN_80165858(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = func_0x80033604();
  *(undefined4 *)((uVar1 & 0xf) * 0x178 + *(int *)(param_1 + 0x234) + 0x60) = 0x3f2f;
  *(undefined1 *)(param_1 + 699) = 1;
  FUN_80166980(param_1,uVar1 & 0xf,9);
  *(undefined1 *)(param_1 + 5) = 1;
  FUN_80164d5c(param_1,param_2,param_3);
  return;
}

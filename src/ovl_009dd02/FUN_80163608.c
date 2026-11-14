/* FUN_80163608
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80163608  body 0x80163608..0x801636e7  size 224 B
 * body sha256 c7fefda9ab4bbf63fa3b335fee77f4fdf0da540291578f13c195dc9cb7e11fa3
 * recovered byte-exact (imported: closed by the cast pass after localtype (56 of 56) (M430))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_009dd02/80163608.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;
typedef unsigned int uint;












void FUN_80163608(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2cd) * 0xd + 6) * 0x1000000 + 0x3f00;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if (iVar1 != 0) {
    FUN_80163564(param_1);
  }
  func_0x80032b5c(param_1,0);
  if (((**(uint **)(param_1 + 0x214) & 0x10000) != 0) && (*(char *)(param_1 + 0x206) == '\0')) {
    uVar2 = FUN_80166838(param_1);
    *(undefined1 *)(param_1 + 0x206) = uVar2;
  }
  return;
}

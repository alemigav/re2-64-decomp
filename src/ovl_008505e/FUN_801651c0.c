/* FUN_801651c0
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x801651c0  body 0x801651c0..0x80165233  size 116 B
 * body sha256 813b73dd13ca5e9c802d99c283b7fbd839e242be9fb3db9e4becdba279616aa8
 * recovered byte-exact (imported: closed by access type (all char  -> unsigned char ) and pinned word for word (M411))
 * provider Ghidra 12.2: body was the head only; this file is the reconstruction, kept in fixtures/decomp/authored/ovl_008505e/801651c0.c
 * extents and pins: fixtures/decomp/recovered.json
 */
typedef unsigned char undefined1;
typedef unsigned int undefined4;
typedef unsigned char byte;












void FUN_801651c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(unsigned char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x160f0300;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
  if (iVar1 != 0) {
    FUN_80165a5c(param_1,1);
    *(undefined1 *)(param_1 + 0x2bf) = 0;
    *(undefined4 *)(param_1 + 4) = 0x1020000;
  }
  return;
}

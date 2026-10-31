/* FUN_800051b8
 * image   boot (boot), base 0x80000480
 * address 0x800051b8  body 0x800051b8..0x8000521b  size 103 B
 * body sha256 ce20d358b27de6bc00881f6f4262149e3c43ea87fb250e31d68a17763d572b47
 * provider record sha256 8f3179d8792dff4b965c846a1f7bffa51fbd85e8640e5146a7fb7fc53c2ebc71
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800051b8(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_80004c9c(param_1);
  _DAT_800128ac = _DAT_800128ac - iVar1 & 0xfffffff8;
  iVar2 = FUN_80004cfc(param_1,_DAT_800128ac,0,0);
  if (iVar2 == 0) {
    trap(0);
  }
  return iVar1;
}

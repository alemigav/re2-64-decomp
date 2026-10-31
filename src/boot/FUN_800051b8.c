/* FUN_800051b8
 * image   boot (boot), base 0x80000480
 * address 0x800051b8  body 0x800051b8..0x8000521b  size 103 B
 * sha256  6aafc6ee7779aee792403a0b616c7a3d5de77acf1f344b63d6b61f29c34080dc
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

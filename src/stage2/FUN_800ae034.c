/* FUN_800ae034
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ae034  body 0x800ae034..0x800ae0d3  size 163 B
 * sha256  e83b334b37610c40304afd91690caa213d5c466fd99589241e59cdea8882dcfc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800ae034(undefined2 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  _DAT_8014e160 = param_1;
  if (0 < _DAT_80157e10) {
    puVar2 = &DAT_80157e20;
    do {
      iVar1 = FUN_800ab43c(&DAT_8014e160,*(undefined4 *)(puVar2 + 4),*(undefined2 *)(puVar2 + 2),0xc
                           ,&LAB_800ae184);
      iVar3 = iVar3 + 1;
      if (iVar1 != 0) {
        return iVar1;
      }
      puVar2 = puVar2 + 8;
    } while (iVar3 < _DAT_80157e10);
  }
  return 0;
}

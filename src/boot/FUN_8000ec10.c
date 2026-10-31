/* FUN_8000ec10
 * image   boot (boot), base 0x80000480
 * address 0x8000ec10  body 0x8000ec10..0x8000ec53  size 71 B
 * sha256  cd4f27b31e523d699b9c9c2e9639f8cb74b8b58399824d3e8cab64070d60e19f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000ec10(undefined4 param_1)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  uVar3 = FUN_800072e0();
  puVar2 = _DAT_800129d4;
  uVar1 = *_DAT_800129d4;
  *(undefined4 *)(_DAT_800129d4 + 0x12) = param_1;
  *puVar2 = uVar1 | 4;
  FUN_80007300(uVar3);
  return;
}

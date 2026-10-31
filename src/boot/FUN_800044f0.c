/* FUN_800044f0
 * image   boot (boot), base 0x80000480
 * address 0x800044f0  body 0x800044f0..0x8000454f  size 99 B
 * sha256  47b2afe37df120c08d56a0169a24961ab75db6a98ab82b24454c8fcb52a26fef
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_800044f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _DAT_80012820;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (iVar1 == 0) {
    _DAT_80012820 = _DAT_8010b6f8;
  }
  FUN_800013b0(_DAT_80012820);
  uVar2 = FUN_800013d4(0x8000);
  *(undefined4 *)(param_1 + 0x4c) = uVar2;
  return param_1;
}

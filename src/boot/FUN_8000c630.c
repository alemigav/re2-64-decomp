/* FUN_8000c630
 * image   boot (boot), base 0x80000480
 * address 0x8000c630  body 0x8000c630..0x8000c773  size 327 B
 * sha256  40289a30b87d3f54754edafa0cd264ea0b071f76d535f19b19ef963d82545029
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_8000c630(int param_1,uint param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  do {
  } while ((_DAT_a4600010 & 3) != 0);
  uVar4 = (uint)*(byte *)(param_1 + 9);
  iVar2 = *(int *)(uVar4 * 4 + -0x7ffed6f0);
  if (iVar2 == param_1) goto LAB_8000c758;
  if (uVar4 == 0) {
    if ((uint)*(byte *)(iVar2 + 5) != (uint)*(byte *)(param_1 + 5)) {
      _DAT_a4600014 = (uint)*(byte *)(param_1 + 5);
    }
    if ((uint)*(byte *)(iVar2 + 6) != (uint)*(byte *)(param_1 + 6)) {
      _DAT_a460001c = (uint)*(byte *)(param_1 + 6);
    }
    if ((uint)*(byte *)(iVar2 + 7) != (uint)*(byte *)(param_1 + 7)) {
      _DAT_a4600020 = (uint)*(byte *)(param_1 + 7);
    }
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (*(byte *)(iVar2 + 8) != uVar3) {
      puVar1 = (uint *)&DAT_a4600018;
LAB_8000c744:
      *puVar1 = uVar3;
    }
  }
  else {
    if ((uint)*(byte *)(iVar2 + 5) != (uint)*(byte *)(param_1 + 5)) {
      _DAT_a4600024 = (uint)*(byte *)(param_1 + 5);
    }
    if ((uint)*(byte *)(iVar2 + 6) != (uint)*(byte *)(param_1 + 6)) {
      _DAT_a460002c = (uint)*(byte *)(param_1 + 6);
    }
    if ((uint)*(byte *)(iVar2 + 7) != (uint)*(byte *)(param_1 + 7)) {
      _DAT_a4600030 = (uint)*(byte *)(param_1 + 7);
    }
    uVar3 = (uint)*(byte *)(param_1 + 8);
    if (*(byte *)(iVar2 + 8) != uVar3) {
      puVar1 = (uint *)&DAT_a4600028;
      goto LAB_8000c744;
    }
  }
  *(int *)(uVar4 * 4 + -0x7ffed6f0) = param_1;
LAB_8000c758:
  *(undefined4 *)(*(uint *)(param_1 + 0xc) | param_2 | 0xa0000000) = param_3;
  return 0;
}

/* FUN_80030324
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80030324  body 0x80030324..0x800303eb  size 203 B
 * sha256  c7ce51d4c273ec926b837e116e9395ebc0e09d3471123161773b5082ace99f7f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80030324(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  if (param_2 != 1) {
    *(undefined4 *)(*param_1 + 0x14) = 0xb;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)();
  }
  uVar1 = FUN_80030edc(param_4,param_5);
  puVar2 = (undefined4 *)FUN_8002fd38(param_1,param_2,0x74);
  *puVar2 = 0;
  puVar2[1] = uVar1;
  puVar2[2] = param_3;
  puVar2[3] = param_5;
  puVar2[8] = 0;
  puVar2[9] = *(undefined4 *)(iVar3 + 0x44);
  *(undefined4 **)(iVar3 + 0x44) = puVar2;
  return;
}

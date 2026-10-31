/* FUN_8006e1bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e1bc  body 0x8006e1bc..0x8006e26f  size 183 B
 * sha256  5b3aaa92fead7098055fc9976260a1dc954ae0c75fd9106d2969919d54cbed0c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_8006e1bc(int param_1,byte *param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar2 = (*(code *)(&PTR_LAB_80113898)[*param_2])();
  pbVar4 = *(byte **)(param_1 + 0x1c);
  while (pbVar4 != param_2 + (param_3 & 0xff)) {
    sVar1 = *(short *)pbVar4;
    *(byte **)(param_1 + 0x1c) = pbVar4 + 2;
    uVar3 = (*(code *)(&PTR_LAB_80113898)[pbVar4[2]])(param_1);
    pbVar4 = *(byte **)(param_1 + 0x1c);
    if (sVar1 == 0) {
      uVar2 = uVar2 & uVar3;
    }
    else {
      uVar2 = uVar2 | uVar3;
    }
  }
  return uVar2;
}

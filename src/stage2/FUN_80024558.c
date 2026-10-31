/* FUN_80024558
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80024558  body 0x80024558..0x80024783  size 86 B
 * sha256  0b82e47ca082f6bb58fed8ed4f8a0f2e80474e861ae0d3d1d901e1b99082a57e
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 * FUN_80024558(undefined4 *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar4 = DAT_801137d8;
  puVar6 = param_1;
  switch(DAT_800e923c) {
  case 0:
    puVar6 = param_1 + 8;
    *param_1 = 0xe3001001;
    param_1[1] = 0;
    param_1[2] = 0xe200001c;
    param_1[3] = 0;
    param_1[4] = 0xe3000a01;
    param_1[5] = 0x200000;
    param_1[6] = 0xa000000;
    param_1[7] = &DAT_800c4f08;
    break;
  case 3:
  case 4:
    *param_1 = 0xe7000000;
    uVar3 = DAT_8010b6fc;
    param_1[1] = 0;
    fVar1 = (float)iVar4;
    param_1[3] = uVar3;
    param_1[2] = iVar4 - 1U & 0xfff | 0xff100000;
    param_1[4] = 0xed000000;
    iVar5 = DAT_801137dc;
    if (iVar4 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)DAT_801137dc;
    if (DAT_801137dc < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    puVar6 = param_1 + 0x10;
    param_1[5] = ((int)(fVar1 * 4.0) & 0xfffU) << 0xc | (int)(fVar2 * 4.0) & 0xfffU;
    param_1[7] = 0x300000;
    param_1[6] = 0xe3000a01;
    param_1[8] = 0xfcffffff;
    param_1[9] = 0xfffe793c;
    param_1[10] = 0xe200001c;
    param_1[0xb] = 0xf0a4000;
    param_1[0xc] = 0xf7000000;
    param_1[0xd] = 0xfffcfffc;
    param_1[0xe] = (iVar4 - 1U & 0x3ff) << 0xe | (iVar5 - 1U & 0x3ff) << 2 | 0xf6000000;
    param_1[0xf] = 0;
  }
  return puVar6;
}

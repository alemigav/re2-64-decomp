/* FUN_80069c60
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80069c60  body 0x80069c60..0x80069dab  size 335 B
 * sha256  d9fce4f5f176963d4af7c9a395bb3d2bcc4674581feb393b99e750ca1a123d89
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
int FUN_80069c60(int param_1,int param_2,int param_3,short *param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = ((ushort)param_4[5] & 0x30) >> 4;
  if (uVar3 == 1) {
    param_2 = *param_4 - param_1;
    uVar1 = param_4[2];
LAB_80069d60:
    uVar3 = (uint)uVar1;
    param_3 = (param_2 * -0x708) / (int)uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (param_2 * -0x708 == -0x80000000)) {
      trap(0x1800);
    }
    bVar2 = param_3 < 0x709;
  }
  else {
    if (uVar3 < 2) {
      bVar2 = param_3 < 0x709;
      if (uVar3 != 0) goto LAB_80069d94;
      uVar3 = (uint)(ushort)param_4[2];
      param_1 = param_1 - ((int)*param_4 + uVar3);
    }
    else {
      if (uVar3 != 2) {
        bVar2 = param_3 < 0x709;
        if (uVar3 != 3) goto LAB_80069d94;
        param_2 = param_4[1] - param_2;
        uVar1 = param_4[3];
        goto LAB_80069d60;
      }
      uVar3 = (uint)(ushort)param_4[3];
      param_1 = param_2 - ((int)param_4[1] + uVar3);
    }
    param_3 = (param_1 * -0x708) / (int)uVar3;
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    if ((uVar3 == 0xffffffff) && (param_1 * -0x708 == -0x80000000)) {
      trap(0x1800);
    }
    bVar2 = param_3 < 0x709;
  }
LAB_80069d94:
  if (!bVar2) {
    param_3 = 0x708;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  return param_3;
}

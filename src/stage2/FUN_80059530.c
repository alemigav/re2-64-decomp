/* FUN_80059530
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059530  body 0x80059530..0x8005956b  size 60 B
 * body sha256 71664f9b63dc13b97984fcf8e6921eda37e6f5527562b54f3d64d40acf790956
 * provider record sha256 e1325246c27805ced9283eca4456a7e29731b10b8b464ef47072a5cd83cbff1f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80059530(uint *param_1)

{
  short sVar1;
  char cVar3;
  int iVar2;
  undefined1 uVar4;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x2000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x78) = 0xfce0;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    FUN_80077adc(0x4010001,param_1 + 10);
    *param_1 = *param_1 & 0xfffffffb;
  case 1:
    if (*(char *)((int)param_1 + 0x1ea) == '\0') {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    FUN_80032b5c(param_1,0);
    FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + 0x96;
    if ((param_1[0x6b] & 1) != 0) {
      uVar4 = 5;
LAB_80059850:
      *(undefined1 *)((int)param_1 + 6) = uVar4;
    }
    break;
  case 2:
    param_1[0x7a] = 0x3000300;
    *(undefined1 *)((int)param_1 + 6) = 3;
    FUN_80077adc(0x22a0001,param_1 + 10);
  case 3:
    FUN_80032b5c(param_1,0);
    cVar3 = FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    sVar1 = *(short *)(param_1 + 0x78);
    *(ushort *)(param_1 + 0x78) = sVar1 + 0xfU;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
    if (0 < (int)((uint)(ushort)(sVar1 + 0xfU) << 0x10)) {
      *(undefined2 *)(param_1 + 0x78) = 0;
    }
    break;
  case 4:
    FUN_800551e0();
    param_1[1] = 0x1000000;
    *(undefined1 *)((int)param_1 + 0x26f) = 0;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
    return;
  case 5:
    param_1[0x7a] = 0x300;
    *(undefined1 *)((int)param_1 + 6) = 6;
    FUN_80077adc(0x2290001,param_1 + 10);
    FUN_80077adc(0x4020001,param_1 + 10);
    FUN_80052bd0(1,0);
    FUN_80052c6c(5,0xfa,0);
  case 6:
    cVar3 = FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
    break;
  case 7:
    param_1[0x7a] = 0x4000300;
    *(undefined1 *)((int)param_1 + 6) = 8;
    *(undefined2 *)(param_1 + 0x7d) = 0x1e;
    if (*(short *)((int)param_1 + 0x1f2) < 0x96) {
      *(undefined2 *)(param_1 + 0x7d) = 0x3c;
    }
    if (*(short *)((int)param_1 + 0x1f2) < 0x46) {
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x32;
    }
    if (*(short *)((int)param_1 + 0x1f2) < 0x1e) {
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x32;
    }
    if (*(short *)((int)param_1 + 0x1f2) == 0) {
      *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 100;
      goto switchD_80059564_caseD_8;
    }
    goto LAB_800597a0;
  case 8:
switchD_80059564_caseD_8:
LAB_800597a0:
    FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x10400);
    iVar2 = FUN_800331b8();
    iVar2 = (uint)*(ushort *)(param_1 + 0x7d) - (iVar2 * 5 + 1);
    *(short *)(param_1 + 0x7d) = (short)iVar2;
    if (iVar2 * 0x10000 < 0) {
      *(undefined1 *)((int)param_1 + 6) = 9;
    }
    break;
  case 9:
    param_1[0x7a] = 0x1000300;
    *(undefined1 *)((int)param_1 + 6) = 10;
    *(undefined1 *)((int)param_1 + 0x26f) = 0;
  case 10:
    iVar2 = FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    if (iVar2 == 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 0xb;
    param_1[0x7a] = 0x6000300;
    return;
  case 0xb:
    iVar2 = FUN_80089d54(param_1,param_1[0x69],param_1[0x86],0x10400);
    uVar4 = 4;
    if (iVar2 == 0) {
      return;
    }
    goto LAB_80059850;
  default:
    break;
  }
  return;
}

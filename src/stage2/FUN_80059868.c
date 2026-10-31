/* FUN_80059868
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80059868  body 0x80059868..0x80059b03  size 671 B
 * body sha256 8a9d87353ccf391438a984113be6680af71e5f1622baa332834046736e987719
 * provider record sha256 6c0b63e64381d10caf4608f9a3aab286092cba540222176287871255b8f6e575
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x80059930) */

void FUN_80059868(uint *param_1)

{
  char cVar3;
  short sVar2;
  int iVar1;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x5000300;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x78) = 400;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
    FUN_80077adc(0x4020001,param_1 + 10);
    *param_1 = *param_1 & 0xfffffffb;
  case 1:
    FUN_80032b5c(param_1,0);
    cVar3 = FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
    if (*(char *)((int)param_1 + 0x1ea) == '\0') {
      sVar2 = *(short *)(param_1 + 0x78) + -0x32;
    }
    else {
      sVar2 = *(short *)(param_1 + 0x78) + -0x14;
    }
    *(short *)(param_1 + 0x78) = sVar2;
    if (*(short *)(param_1 + 0x78) < 0) {
      *(undefined2 *)(param_1 + 0x78) = 0;
    }
    break;
  case 2:
    param_1[0x7a] = 0x4000300;
    *(undefined1 *)((int)param_1 + 6) = 3;
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
      goto switchD_80059898_caseD_3;
    }
    goto LAB_80059a24;
  case 3:
switchD_80059898_caseD_3:
LAB_80059a24:
    FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x10400);
    iVar1 = FUN_800331b8();
    iVar1 = (uint)*(ushort *)(param_1 + 0x7d) - (iVar1 * 3 + 1);
    *(short *)(param_1 + 0x7d) = (short)iVar1;
    if (iVar1 * 0x10000 < 0) {
      *(undefined1 *)((int)param_1 + 6) = 4;
    }
    break;
  case 4:
    param_1[0x7a] = 0x1000300;
    *(undefined1 *)((int)param_1 + 6) = 5;
    *(undefined1 *)((int)param_1 + 0x26f) = 0;
  case 5:
    iVar1 = FUN_80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    if (iVar1 == 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 6) = 6;
    param_1[0x7a] = 0x6000300;
    return;
  case 6:
    iVar1 = FUN_80089d54(param_1,param_1[0x69],param_1[0x86],0x10400);
    if (iVar1 != 0) {
      FUN_800551e0();
      param_1[1] = 0x1000000;
      *(undefined1 *)((int)param_1 + 0x26f) = 0;
      *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
    }
  default:
    break;
  }
  return;
}

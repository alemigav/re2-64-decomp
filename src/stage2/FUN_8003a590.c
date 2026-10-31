/* FUN_8003a590
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a590  body 0x8003a590..0x8003aa3b  size 1199 B
 * body sha256 6562484bf3dc5c42747cb4f328fd7ca8d647f6db7b83ca4196bbf5310962c0dd
 * provider record sha256 af2a829de1b49ab65a8bccfe32cb71a988c33ba94566ccfd182810c83096710e
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a590(void)

{
  short sVar1;
  short sVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar9;
  uint uVar7;
  uint uVar8;
  undefined4 uVar10;
  short sVar11;
  uint uVar12;
  short local_40;
  short local_3e;
  undefined2 local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar3 = DAT_800ebb94;
  local_28 = 0xff380000;
  local_24 = 0x640032;
  switch(DAT_800ebb94[2]) {
  case 0:
    *(undefined2 *)(DAT_800ebb94 + 0x18) = *(undefined2 *)(DAT_800ebb94 + 0x12);
    DAT_80131781 = 1;
    local_38 = (int)*(short *)(puVar3 + 0x34);
    local_34 = (int)*(short *)(puVar3 + 0x36);
    local_30 = (int)*(short *)(puVar3 + 0x38);
    FUN_80077adc(0x1100001,&local_38);
    FUN_800609e0(0x120,(int)*(short *)(DAT_800ebb94 + 0x22),&local_28,0x3000e);
    sVar11 = 0;
    if (local_34 < iRam00000124) {
      local_34 = iRam00000124 - local_34;
LAB_8003a6ac:
      sVar11 = (short)(local_34 / 5);
    }
    else if (iRam00000124 < local_34) {
      local_34 = local_34 - iRam00000124;
      goto LAB_8003a6ac;
    }
    local_38 = iRam00000120 - *(short *)(DAT_800ebb94 + 0x34);
    if (local_38 < 0) {
      local_38 = -local_38;
    }
    local_34 = iRam00000124 - *(short *)(DAT_800ebb94 + 0x36);
    if (local_34 < 0) {
      local_34 = -local_34;
    }
    local_30 = iRam00000128 - *(short *)(DAT_800ebb94 + 0x38);
    if (local_30 < 0) {
      local_30 = -local_30;
    }
    iVar4 = FUN_80040bb4(local_38 * local_38 + local_30 * local_30);
    iVar5 = FUN_80040bb4(local_38 * local_38 + local_30 * local_30);
    uVar6 = FUN_80040bb4(local_34 * local_34 + iVar4 * iVar5);
    sVar9 = FUN_80078824((int)*(short *)(DAT_800ebb94 + 0x34),(int)*(short *)(DAT_800ebb94 + 0x38),
                         iRam00000120,iRam00000128);
    sVar1 = *(short *)(DAT_800ebb94 + 0x22);
    local_40 = *(short *)(DAT_800ebb94 + 0x2c);
    local_3e = *(short *)(DAT_800ebb94 + 0x2e);
    uVar6 = uVar6 / 0x1b0;
    local_3c = *(undefined2 *)(DAT_800ebb94 + 0x30);
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    uVar12 = (uint)(iRam00000124 - *(short *)(DAT_800ebb94 + 0x36)) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    do {
      uVar6 = uVar6 - 1;
      uVar7 = FUN_80038a20(0x6012600,((int)sVar9 - (int)sVar1) * 0x10000 >> 0x10,DAT_800ebb94 + 0x4c
                           ,&local_40);
      if ((uVar7 & 0xff) < 0xff) {
        iVar4 = (uVar7 & 0xff) * 0x7c;
        uVar7 = FUN_80033604();
        *(short *)(&DAT_800ebdec + iVar4) = (short)((uVar7 & 0xff) % 0x1e) * 10 + -0x96;
        uVar7 = FUN_80033604();
        *(short *)(&DAT_800ebdee + iVar4) = (short)((uVar7 & 0xff) % 0x32) * 0x28 + -1000;
        uVar7 = FUN_80033604();
        uVar8 = FUN_80033604();
        sVar2 = sVar11;
        if ((uVar8 & 2) != 0) {
          sVar2 = sVar11 + 0x800;
        }
        *(short *)(&DAT_800ebdf0 + iVar4) = (short)((uVar7 & 0xff) % 0x14) * 0x1e + 0x338 + sVar2;
      }
      else {
        uVar6 = 0;
      }
      local_3e = local_3e + 0x1b0;
      local_40 = local_40 - (short)uVar12;
    } while (uVar6 != 0);
    FUN_800274f8(0x100,0,7,1);
    uVar10 = 0x2000;
    break;
  case 1:
    uVar10 = 0x1800;
    break;
  case 2:
    uVar10 = 0x1600;
    break;
  case 3:
    FUN_80027650(0);
    goto LAB_8003aa04;
  case 4:
    FUN_800274f8(0x100,0,7,1);
    uVar10 = 0x1400;
    break;
  case 5:
    uVar10 = 0x1200;
    break;
  case 6:
    FUN_80027650(0);
    puVar3 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar3 = 0;
    *(undefined2 *)(puVar3 + 0x18) = 0;
  default:
    goto LAB_8003aa04;
  }
  FUN_800275c0(0,uVar10,0x8421,0);
LAB_8003aa04:
  DAT_800ebb94[2] = DAT_800ebb94[2] + '\x01';
  return;
}

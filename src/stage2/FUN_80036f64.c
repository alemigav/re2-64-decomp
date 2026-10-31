/* FUN_80036f64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036f64  body 0x80036f64..0x800371a3  size 579 B
 * body sha256 ea43b66a5dbcc806b50b9655b498fbb9f5234b95a16f61b6c89ba2d9cc924517
 * provider record sha256 812fb674e1aaf7f41fc4ce2a5f942b98d337c3f9c311564a59763b22fd3cd575
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036f64(int param_1,int param_2,short param_3)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_s0;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0x7fff0000;
  local_1c = 0;
  FUN_8008383c((int)*(short *)(param_1 + 0x66),*(undefined4 *)(param_1 + 0x70),&local_20,&local_20);
  uVar1 = FUN_8006a7ec(*(undefined4 *)(param_1 + 0x70));
  switch(uVar1) {
  case 0:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                         (int)*(short *)(param_2 + 2),(int)*(short *)(param_2 + 10));
    iVar6 = (int)sVar2;
    iVar4 = (int)local_20._0_2_;
    iVar5 = (int)local_1c._0_2_;
    break;
  case 1:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                         (int)*(short *)(param_2 + 2),(int)*(short *)(param_2 + 10));
    iVar4 = -(int)sVar2;
    iVar5 = (int)local_20._0_2_;
    iVar6 = (int)local_1c._0_2_;
    goto LAB_80037134;
  case 2:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x32),(int)*(short *)(param_1 + 0x2e),
                         (int)*(short *)(param_2 + 10),(int)*(short *)(param_2 + 6));
    iVar6 = (int)sVar2;
    iVar4 = (int)local_1c._0_2_;
    iVar5 = (int)local_20._2_2_;
    break;
  case 3:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x32),(int)*(short *)(param_1 + 0x2e),
                         (int)*(short *)(param_2 + 10),(int)*(short *)(param_2 + 6));
    iVar4 = -(int)sVar2;
    iVar5 = (int)local_1c._0_2_;
    iVar6 = (int)local_20._2_2_;
    goto LAB_80037134;
  case 4:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x2e),(int)*(short *)(param_1 + 0x2a),
                         (int)*(short *)(param_2 + 6),(int)*(short *)(param_2 + 2));
    iVar6 = (int)sVar2;
    iVar4 = (int)local_20._2_2_;
    iVar5 = (int)local_20._0_2_;
    break;
  case 5:
    sVar2 = FUN_80032d14((int)*(short *)(param_1 + 0x2e),(int)*(short *)(param_1 + 0x2a),
                         (int)*(short *)(param_2 + 6),(int)*(short *)(param_2 + 2));
    iVar4 = -(int)sVar2;
    iVar5 = (int)local_20._2_2_;
    iVar6 = (int)local_20._0_2_;
LAB_80037134:
    sVar2 = FUN_80032d14(0,0,iVar5,iVar6);
    unaff_s0 = iVar4 + sVar2;
  default:
    goto switchD_80036ff0_default;
  }
  sVar2 = FUN_80032d14(0,0,iVar4,iVar5);
  unaff_s0 = iVar6 - sVar2;
switchD_80036ff0_default:
  uVar3 = unaff_s0 + param_3 & 0xfff;
  if ((int)param_3 << 1 <= (int)uVar3) {
    if (uVar3 < 0x801) {
      param_3 = *(short *)(param_1 + 0x66) + param_3;
    }
    else {
      param_3 = *(short *)(param_1 + 0x66) - param_3;
    }
    *(short *)(param_1 + 0x66) = param_3;
  }
  return;
}

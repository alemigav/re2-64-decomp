/* FUN_800371a4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800371a4  body 0x800371a4..0x8003730f  size 367 B
 * sha256  18fb729c98ecb1dcfccb1ac64554375fbfe2abf29ffe46f5fab9e6c9b7617f4f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800371a4(int param_1,int param_2,short param_3)

{
  undefined4 uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = 0x7fff0000;
  local_14 = 0;
  FUN_8008383c((int)*(short *)(param_1 + 0x66),*(undefined4 *)(param_1 + 0x70),&local_18,&local_18);
  uVar1 = FUN_8006a7ec(*(undefined4 *)(param_1 + 0x70));
  switch(uVar1) {
  case 0:
    iVar4 = (int)local_18._0_2_;
    iVar5 = (int)local_14._0_2_;
    break;
  case 1:
    iVar4 = (int)local_18._0_2_;
    iVar5 = (int)local_14._0_2_;
    goto LAB_800372a4;
  case 2:
    iVar4 = (int)local_14._0_2_;
    iVar5 = (int)local_18._2_2_;
    break;
  case 3:
    iVar4 = (int)local_14._0_2_;
    iVar5 = (int)local_18._2_2_;
    goto LAB_800372a4;
  case 4:
    iVar4 = (int)local_18._2_2_;
    iVar5 = (int)local_18._0_2_;
    break;
  case 5:
    iVar4 = (int)local_18._2_2_;
    iVar5 = (int)local_18._0_2_;
LAB_800372a4:
    sVar2 = FUN_80032d14(0,0,iVar4,iVar5);
    param_2 = sVar2 - param_2;
  default:
    goto switchD_8003722c_default;
  }
  sVar2 = FUN_80032d14(0,0,iVar4,iVar5);
  param_2 = param_2 - sVar2;
switchD_8003722c_default:
  uVar3 = param_2 + param_3 & 0xfff;
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

/* FUN_8003c61c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003c61c  body 0x8003c61c..0x8003c8d3  size 699 B
 * sha256  c0a3d6c048946a6258bb3b7cbd14dd9a15a418365acb1390dc0ef676068cc1f6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003c61c(void)

{
  byte bVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_88 [80];
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  puVar2 = DAT_800ebb94;
  local_28 = 0xf8300000;
  local_24 = 0x3e801f4;
  local_20 = 0xfc180000;
  local_1c = 0x1f400fa;
  switch(*(undefined2 *)(DAT_800ebb94 + 0x12)) {
  case 0:
    local_38 = (int)*(short *)(DAT_800ebb94 + 0x34);
    bVar1 = DAT_800ebb94[0x1e];
    local_34 = (int)*(short *)(DAT_800ebb94 + 0x36);
    local_30 = (int)*(short *)(DAT_800ebb94 + 0x38);
    *(undefined2 *)(DAT_800ebb94 + 0x18) = 0x8400;
    *puVar2 = 0;
    DAT_800ebb94[1] = 0x2f;
    if (DAT_800ebb94[0x1e] == '\f') {
      FUN_80077adc(0x1110001,&local_38);
      FUN_800609e0(&local_38,(int)*(short *)(DAT_800ebb94 + 0x22),
                   auStack_88 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
      local_34 = local_34 + 900;
      FUN_800609e0(&local_38,(int)*(short *)(DAT_800ebb94 + 0x22),
                   auStack_88 + (uint)(byte)DAT_800ebb94[0x1e] * 8,0x10020009);
    }
    else {
      FUN_80077adc(0x1140001,&local_38);
    }
    uVar3 = (bVar1 - 0xc) * 0xa00 & 0xffff;
    if (DAT_800ebb94[0xb] == -1) {
      *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -0x1d6;
    }
    uVar4 = uVar3 + 0x1700;
    FUN_80038a20(uVar4 | 0x31f0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    FUN_80038a20(uVar3 + 0x1f00 | 0x40c0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    FUN_80038a20(uVar4 | 0x41d0000,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 1;
    break;
  case 1:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 2;
    break;
  case 2:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 3;
    break;
  case 3:
    *(undefined2 *)(DAT_800ebb94 + 0x12) = 4;
    break;
  case 4:
    if (DAT_800ebb94[0xb] == -1) {
      *(short *)(DAT_800ebb94 + 0x36) = *(short *)(DAT_800ebb94 + 0x36) + -600;
    }
    FUN_80038a20(0x4152700,0,&DAT_800e9028,DAT_800ebb94 + 0x34);
    puVar2 = DAT_800ebb94;
    DAT_800ebb94[1] = 0;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 0x18) = 0;
  }
  return;
}

/* FUN_80032dbc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032dbc  body 0x80032dbc..0x80032e73  size 187 B
 * sha256  1fe41485e61cbfadbc88eeeadebbf3a6eb2329756658be49918b250646912d9e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032dbc(int param_1,short param_2,short param_3,int param_4)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  
  uVar1 = FUN_80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),(int)param_2,
                       (int)param_3);
  if (((int)(short)param_4 & 0x8000U) != 0) {
    param_4 = -(int)(short)param_4;
    uVar1 = uVar1 + 0x800 & 0xfff;
  }
  uVar3 = param_4 + (uVar1 - *(ushort *)(param_1 + 0x66)) & 0xfff;
  if ((int)uVar3 < (param_4 << 0x10) >> 0xf) {
    *(short *)(param_1 + 0x66) = (short)uVar1;
  }
  else {
    sVar2 = *(ushort *)(param_1 + 0x66) - (short)param_4;
    *(short *)(param_1 + 0x66) = sVar2;
    if (uVar3 < 0x801) {
      *(short *)(param_1 + 0x66) = sVar2 + (short)param_4 * 2;
    }
  }
  return;
}

/* FUN_80032ef4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80032ef4  body 0x80032ef4..0x80032f63  size 115 B
 * sha256  fef0d0533c4b37fef03ba6511302aecc121152bd6d3735e4b5672b3296df160c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80032ef4(int param_1,uint param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  
  if (((int)(short)param_3 & 0x8000U) != 0) {
    param_3 = -(int)(short)param_3;
    param_2 = param_2 + 0x800 & 0xfff;
  }
  uVar2 = param_3 + (param_2 - *(ushort *)(param_1 + 0x66)) & 0xfff;
  sVar1 = *(ushort *)(param_1 + 0x66) - (short)param_3;
  if ((int)uVar2 < (param_3 << 0x10) >> 0xf) {
    *(short *)(param_1 + 0x66) = (short)param_2;
    return;
  }
  *(short *)(param_1 + 0x66) = sVar1;
  if (uVar2 < 0x801) {
    *(short *)(param_1 + 0x66) = sVar1 + (short)param_3 * 2;
  }
  return;
}

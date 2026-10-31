/* FUN_800608c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800608c8  body 0x800608c8..0x80060957  size 147 B
 * body sha256 e6271ebe153d820e78d4cc4e7c991e40424e0ff6265de798cf751c74b31f0eb5
 * provider record sha256 5f9cf25b1d3548929c1dc18c8fd5ca9550d045a2c292da979ef296e014a43d00
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800608c8(short *param_1,undefined2 *param_2)

{
  undefined2 uVar2;
  undefined4 uVar1;
  short sVar3;
  
  uVar2 = FUN_80060958((int)*param_1,(int)param_1[2]);
  uVar1 = FUN_80040bb4((int)*param_1 * (int)*param_1 + (int)param_1[2] * (int)param_1[2]);
  sVar3 = FUN_80060958(uVar1,-(int)param_1[1]);
  *param_2 = 0;
  param_2[1] = uVar2;
  param_2[2] = sVar3 - 0x400U & 0xfff;
  return;
}

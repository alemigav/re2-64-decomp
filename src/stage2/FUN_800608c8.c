/* FUN_800608c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800608c8  body 0x800608c8..0x80060957  size 147 B
 * sha256  511a6cfcf88cfb3e7909c0e93c5f29f7aaba68df4d3460ca0a6aa2118f6b6d8b
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

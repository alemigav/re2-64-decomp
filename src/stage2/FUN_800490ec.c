/* FUN_800490ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800490ec  body 0x800490ec..0x800491cb  size 227 B
 * sha256  587a7ecca3a4b215b37352d95a7edcb81f485e969b45a7774e736f7bc4d600b1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800490ec(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar3 = *(float *)(param_1 + 4);
  fVar4 = *(float *)(param_1 + 0x10);
  fVar5 = *(float *)(param_1 + 0x1c);
  *(float *)(param_1 + 4) = fVar3 * fVar2 - *(float *)(param_1 + 8) * fVar1;
  *(float *)(param_1 + 8) = fVar3 * fVar1 + *(float *)(param_1 + 8) * fVar2;
  *(float *)(param_1 + 0x10) = fVar4 * fVar2 - *(float *)(param_1 + 0x14) * fVar1;
  *(float *)(param_1 + 0x14) = fVar4 * fVar1 + *(float *)(param_1 + 0x14) * fVar2;
  *(float *)(param_1 + 0x1c) = fVar5 * fVar2 - *(float *)(param_1 + 0x20) * fVar1;
  *(float *)(param_1 + 0x20) = fVar5 * fVar1 + *(float *)(param_1 + 0x20) * fVar2;
  return;
}

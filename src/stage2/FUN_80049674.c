/* FUN_80049674
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80049674  body 0x80049674..0x800497b3  size 323 B
 * sha256  7b953146db4a071475e42aaa4154b52686fcbe9b16f3b345cfc08977d2eb42f6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80049674(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar6 = param_1[2];
  fVar5 = param_1[5];
  fVar3 = param_1[6];
  fVar4 = param_1[9];
  param_1[2] = -*param_1 * fVar1 + param_1[2] * fVar2;
  param_1[5] = -param_1[3] * fVar1 + param_1[5] * fVar2;
  param_1[6] = fVar3 * fVar2 + param_1[8] * fVar1;
  *param_1 = *param_1 * fVar2 + fVar6 * fVar1;
  param_1[3] = param_1[3] * fVar2 + fVar5 * fVar1;
  param_1[8] = -fVar3 * fVar1 + param_1[8] * fVar2;
  param_1[9] = fVar4 * fVar2 + param_1[0xb] * fVar1;
  param_1[0xb] = -fVar4 * fVar1 + param_1[0xb] * fVar2;
  return;
}

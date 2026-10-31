/* FUN_800492b4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800492b4  body 0x800492b4..0x80049393  size 227 B
 * body sha256 c59b1cae122222ac5e387b988067d1211624ec23dbd6d3117520ba907b3f8c2b
 * provider record sha256 7475263e56fe3ad329a2ddffb62ea5135fa7320fc200fd1f8db527e170a1e524
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800492b4(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = (float)func_0x8000d050(param_2);
  fVar2 = (float)func_0x80006be0(param_2);
  fVar3 = *param_1;
  fVar4 = param_1[3];
  fVar5 = param_1[6];
  *param_1 = fVar3 * fVar2 - param_1[1] * fVar1;
  param_1[1] = fVar3 * fVar1 + param_1[1] * fVar2;
  param_1[3] = fVar4 * fVar2 - param_1[4] * fVar1;
  param_1[4] = fVar4 * fVar1 + param_1[4] * fVar2;
  param_1[6] = fVar5 * fVar2 - param_1[7] * fVar1;
  param_1[7] = fVar5 * fVar1 + param_1[7] * fVar2;
  return;
}

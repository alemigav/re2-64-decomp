/* FUN_80001698
 * image   boot (boot), base 0x80000480
 * address 0x80001698  body 0x80001698..0x800022bb  size 262 B
 * body sha256 d8470768786a62a0da1bd6f0b82d3b1374d43b2be4433349f29651535a728d0a
 * provider record sha256 06c1a2340fc9bc106aead8f1eb6ef1f5590933e97156ef1b83de12c3422a10ec
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80001698(uint *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *param_2;
  iVar3 = param_2[1];
  uVar4 = param_1[0xc];
  if (*param_1 < 10) {
                    /* WARNING: Could not emulate address calculation at 0x80001720 */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 * 4 + -0x7ffee9a8))();
    return;
  }
  param_1[8] = param_1[8];
  param_1[7] = param_1[7];
  iVar1 = *param_2;
  param_2[1] = iVar3;
  *param_2 = iVar2;
  param_2[2] = param_2[2] + (iVar2 - iVar1);
  param_1[0xc] = uVar4;
  FUN_80004370(param_1,param_2,0xfffffffe);
  return;
}

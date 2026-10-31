/* FUN_800b62c0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b62c0  body 0x800b62c0..0x800b63ab  size 239 B
 * sha256  ae9fe0d5a5bd288dfa199e0e06e3513deaa0995a8b7ccac402932fecf077ac12
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800b62c0(uint param_1,int param_2,short *param_3,undefined2 *param_4)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  undefined2 *puVar5;
  
  if ((int)(param_1 - 7) < 1) {
    param_1 = (uint)(char)(&DAT_800b63ac)[param_1];
    iVar2 = (int)param_1 >> 4;
  }
  else {
    iVar2 = (int)(param_1 - 8) >> 3;
  }
  iVar3 = 0xd;
  psVar4 = param_3;
  do {
    *psVar4 = (short)(((int)((*psVar4 * 0x2000 + -0x7000) * ((param_1 & 7) * 0x800 + 0x47ff) +
                            0x4000) >> 0xf) + (1 << (-iVar2 + 5U & 0x1f)) >> (-iVar2 + 6U & 0x1f));
    iVar3 = iVar3 + -1;
    psVar4 = psVar4 + 1;
  } while (0 < iVar3);
  iVar2 = 0x28;
  puVar5 = param_4;
  do {
    *puVar5 = 0;
    iVar2 = iVar2 + -1;
    puVar5 = puVar5 + 1;
  } while (0 < iVar2);
  psVar4 = param_4 + param_2;
  iVar2 = 0xd;
  do {
    sVar1 = *param_3;
    param_3 = param_3 + 1;
    *psVar4 = sVar1;
    iVar2 = iVar2 + -1;
    psVar4 = psVar4 + 3;
  } while (0 < iVar2);
  return;
}

/* FUN_8003a21c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8003a21c  body 0x8003a21c..0x8003a363  size 331 B
 * sha256  85b338811716962f34a69d6f3d3b7c953b533fbe589bd970ce517cd1b4941b68
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8003a21c(void)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  FUN_80039ba8();
  *(char *)(DAT_800ebb94 + 8) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 8) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  *(char *)(DAT_800ebb94 + 9) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 9) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  *(char *)(DAT_800ebb94 + 10) =
       (char)((int)((int)*(char *)(DAT_800ebb94 + 10) * (uint)*(ushort *)(DAT_800ebb94 + 0x3a)) /
             3000);
  iVar3 = DAT_800ebb94;
  uVar4 = (uint)*(ushort *)(DAT_800ebb94 + 0x3a);
  psVar1 = (short *)(DAT_800ebb94 + 0xe);
  sVar2 = *(short *)(DAT_800ebb94 + 0x10);
  *(short *)(DAT_800ebb94 + 0xc) =
       (short)((int)((int)*(short *)(DAT_800ebb94 + 0xc) * uVar4) / 3000);
  *(short *)(iVar3 + 0xe) = (short)((int)((int)*psVar1 * uVar4) / 3000);
  *(short *)(iVar3 + 0x10) = (short)((int)((int)sVar2 * uVar4) / 3000);
  return;
}

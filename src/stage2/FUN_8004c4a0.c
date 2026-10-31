/* FUN_8004c4a0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004c4a0  body 0x8004c4a0..0x8004c563  size 199 B
 * sha256  05e95071ca71f872e38a6254a6823b3bcbb48d2a0dacfb8bf2a5a8f7472e8f3a
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004c4a0(int param_1)

{
  short *psVar1;
  short sVar4;
  int iVar2;
  uint uVar3;
  short *psVar5;
  short *psVar6;
  
  psVar5 = *(short **)(param_1 + 0xd008);
  psVar1 = (short *)(param_1 + 0xc808);
  if (psVar5 != psVar1) {
    do {
      sVar4 = FUN_800844cc((int)*psVar1);
      psVar6 = psVar1 + 2;
      iVar2 = FUN_800844cc((int)psVar1[1]);
      iVar2 = (int)sVar4 + iVar2 * 0x10000;
      uVar3 = FUN_800844cc((int)*psVar6);
      if ((uVar3 & 0x200) == 0) {
        psVar1 = (short *)FUN_8004c564(psVar6,iVar2,param_1);
      }
      else {
        psVar1 = (short *)FUN_8004c70c(psVar6,iVar2,param_1);
      }
    } while (psVar1 < psVar5);
  }
  return;
}

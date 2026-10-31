/* FUN_80096f68
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80096f68  body 0x80096f68..0x80097067  size 259 B
 * body sha256 6745ac96c7a4e931ddf05639298b0250a688f800023df2c0edfc28844349710e
 * provider record sha256 a4d57bed935acc2dfe4115475d533d197c488952d59275fd901ae6d791899f67
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80096f68(int param_1)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  FUN_80043620();
  sVar2 = DAT_8012bfe6;
  sVar1 = DAT_8012bfe4;
  iVar5 = 6;
  if (param_1 == 0) {
    DAT_801312ea = 0x55;
  }
  else {
    iVar5 = 0x11;
    DAT_801312ea = 0x91;
  }
  psVar3 = (short *)(&UNK_801312e0 + iVar5 * 4);
  iVar4 = DAT_800c52dc + 0x3bbf4;
  DAT_801312ee = DAT_801312ea;
  do {
    iVar5 = iVar5 + -1;
    FUN_800478b8(iVar4,psVar3[-2] + sVar1,psVar3[-1] + sVar2);
    DAT_800df8b0 = FUN_80043988(DAT_800df8b0,iVar4,0,0);
    psVar3 = psVar3 + -2;
    iVar4 = iVar4 + 0x14;
  } while (iVar5 != 0);
  return;
}

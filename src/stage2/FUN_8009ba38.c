/* FUN_8009ba38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ba38  body 0x8009ba38..0x8009bb6f  size 315 B
 * body sha256 0fbce02b6e1df87e0f2bdd9ff829600c56eee772af726c2e983d561e4044cf65
 * provider record sha256 81c65c12cf0c1629406b5986562fcca8bcb4e2fff73ce2f43d3a22330635b7ec
 * callees 6 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8009ba90) */

void FUN_8009ba38(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (DAT_80132114 < DAT_801320fc) {
    DAT_80132114 = DAT_801320fc;
  }
  DAT_8012483c = 6;
  iVar3 = 0;
  piVar1 = DAT_80132118 + 0x1e;
  piVar2 = DAT_80132118;
  do {
    if (*piVar2 != 0) {
      FUN_80040e58(piVar2 + 0x19,piVar2 + 5);
      FUN_800424ec(piVar1[-2],piVar2 + 5,piVar2 + 0x11);
      FUN_800411b8(piVar2 + 0x11,piVar2 + 0x38);
      FUN_800855d8(piVar1);
    }
    iVar3 = iVar3 + 1;
    piVar1 = piVar1 + 0x7a;
    piVar2 = piVar2 + 0x7a;
  } while (iVar3 < 10);
  return;
}

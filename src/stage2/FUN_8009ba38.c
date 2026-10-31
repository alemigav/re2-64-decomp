/* FUN_8009ba38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009ba38  body 0x8009ba38..0x8009bb6f  size 315 B
 * sha256  e0dbc195637955301c035582990ca81e39344a67e0c82bc9d2edae410fa9a3ce
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

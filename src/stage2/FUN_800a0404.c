/* FUN_800a0404
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a0404  body 0x800a0404..0x800a0517  size 279 B
 * body sha256 2da17526ac7ef0667b81c8ccd3f52b425491150a4985e2a10e17a033ca36d369
 * provider record sha256 d3cf9a7ba48a013d1850041f606f1a7e9d10b929c177629e8fe26778b159388a
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_800a0404(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  
  piVar2 = *(int **)(_DAT_80143c58 + 0xf78);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    do {
      iVar1 = _DAT_80143c58;
      piVar6 = (int *)*piVar2;
      if (piVar2[5] + *(int *)(_DAT_80143c58 + 0x120) < piVar2[3]) {
        uVar5 = piVar2[4] + *(int *)(_DAT_80143c58 + 0x118);
        piVar2[4] = uVar5 & 0xffff;
        piVar2[5] = piVar2[5] + ((int)uVar5 >> 0x10) + *(int *)(iVar1 + 0x11c);
      }
      else {
        FUN_800a8248(piVar2[2]);
        if (*piVar2 != 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
        }
        if ((int *)piVar2[1] == (int *)0x0) {
          *(int *)(_DAT_80143c58 + 0xf78) = *piVar2;
        }
        else {
          *(int *)piVar2[1] = *piVar2;
        }
        iVar1 = _DAT_80143c58;
        iVar4 = *(int *)(_DAT_80143c58 + 0xf7c);
        *piVar2 = iVar4;
        if (iVar4 != 0) {
          *(int **)(*(int *)(iVar1 + 0xf7c) + 4) = piVar2;
        }
        iVar1 = _DAT_80143c58;
        piVar2[1] = 0;
        *(int **)(iVar1 + 0xf7c) = piVar2;
      }
      uVar3 = 1;
      piVar2 = piVar6;
    } while (piVar6 != (int *)0x0);
  }
  return uVar3;
}

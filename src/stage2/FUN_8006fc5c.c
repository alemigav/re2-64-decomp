/* FUN_8006fc5c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006fc5c  body 0x8006fc5c..0x8006fd2f  size 215 B
 * body sha256 85e2373099e4e69fe9d25bb8c98e637cbabe535060540fc3a54febff1814727a
 * provider record sha256 6745f750ddf1f699afdd9985d74a45af898dc036ddbf09020bfed27a7b0653fc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006fc5c(int param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  sVar1 = *(short *)(iVar2 + 4);
  psVar3 = (short *)(*(int *)(*(int *)(param_1 + 0x154) + 0x234) + *(char *)(iVar2 + 2) * 0x178);
  switch(*(undefined1 *)(iVar2 + 3)) {
  case 0:
    psVar3[0x30] = sVar1;
    sVar1 = FUN_800844cc((int)sVar1);
    psVar3[0x66] = sVar1;
    break;
  case 1:
    *(char *)(psVar3 + 0x31) = (char)sVar1;
    *(char *)(psVar3 + 0x67) = (char)sVar1;
    break;
  case 2:
    psVar3[1] = sVar1;
    break;
  case 3:
    *psVar3 = sVar1;
    break;
  case 4:
    psVar3[0x2c] = sVar1;
    break;
  case 5:
    psVar3[0x2d] = sVar1;
    break;
  case 6:
    psVar3[0x2e] = sVar1;
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 6;
  return 1;
}

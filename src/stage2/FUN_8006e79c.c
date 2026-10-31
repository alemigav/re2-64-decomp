/* FUN_8006e79c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e79c  body 0x8006e79c..0x8006e7e3  size 75 B
 * body sha256 53686e9895b55a9c69a1eeede57450db704af09d7296882edaec9c473256853f
 * provider record sha256 170e1b042c6abb17cea93541ac8eec71671ed836457fc23661d1089be63f9d81
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e79c(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar4 + 2);
  bVar2 = *(byte *)(iVar4 + 3);
  sVar3 = *(short *)(iVar4 + 4);
  *(int *)(param_1 + 0x1c) = iVar4 + 6;
  FUN_8006e838(uVar1,&DAT_800e8c78 + bVar2,(int)sVar3);
  return 1;
}

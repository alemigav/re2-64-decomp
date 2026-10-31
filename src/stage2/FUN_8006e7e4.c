/* FUN_8006e7e4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e7e4  body 0x8006e7e4..0x8006e837  size 87 B
 * sha256  a03c78d53522cb97a3a9f86b928ca728de8018ded93ad5a945e635d2ea72c758
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006e7e4(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar4 + 1);
  bVar2 = *(byte *)(iVar4 + 2);
  sVar3 = (&DAT_800e8c78)[*(byte *)(iVar4 + 3)];
  *(int *)(param_1 + 0x1c) = iVar4 + 4;
  FUN_8006e838(uVar1,&DAT_800e8c78 + bVar2,(int)sVar3);
  return 1;
}

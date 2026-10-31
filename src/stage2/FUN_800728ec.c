/* FUN_800728ec
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800728ec  body 0x800728ec..0x80072977  size 143 B
 * body sha256 bbfd73b881bc88a9b34699e70266053f0c23bc25f736879b662d36824a145076
 * provider record sha256 272348c07f9c972c0e0f9556d1762aabbd1a8aac06d026d6e48ca192e25970d3
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800728ec(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x1c) = iVar3 + 3;
  iVar1 = FUN_8008c51c(*(undefined1 *)(iVar3 + 1));
  if (-1 < iVar1) {
    iVar1 = iVar1 * 4;
    cVar2 = (&DAT_800e8ec9)[iVar1] - *(char *)(iVar3 + 2);
    (&DAT_800e8ec9)[iVar1] = cVar2;
    if (cVar2 == '\0') {
      (&DAT_800e8ec8)[iVar1] = 0;
      (&DAT_800e8ec9)[iVar1] = 0;
      (&DAT_800e8eca)[iVar1] = 0;
    }
    FUN_8008c568();
  }
  return 1;
}

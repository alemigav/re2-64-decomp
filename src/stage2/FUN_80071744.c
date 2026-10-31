/* FUN_80071744
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071744  body 0x80071744..0x8007179f  size 95 B
 * body sha256 8441cb2eb621cd7b9041f99cf0e1fa344fdb96e8dead86d8bfce78a742d5dd89
 * provider record sha256 cf48eee5b29fbf9b34f1662d5c190efcdc5d0b927720917160411a467616ec03
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071744(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar1 = FUN_800717a0((int)*(char *)(iVar2 + 4),(int)*(char *)(iVar2 + 5));
  FUN_80039020(*(undefined1 *)(iVar2 + 1),*(undefined1 *)(iVar2 + 2),*(undefined1 *)(iVar2 + 3),
               uVar1);
  *(int *)(param_1 + 0x1c) = iVar2 + 6;
  return 1;
}

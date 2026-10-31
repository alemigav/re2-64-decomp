/* FUN_80073610
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073610  body 0x80073610..0x80073657  size 75 B
 * sha256  e519d65a1bc3acd262a0963f03dc9bbda3e2059162d8626ce12927cd59910194
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073610(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_80052c6c(*(undefined2 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 1),*(undefined2 *)(iVar1 + 4));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 6;
  return 1;
}

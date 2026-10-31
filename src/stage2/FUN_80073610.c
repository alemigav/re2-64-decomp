/* FUN_80073610
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073610  body 0x80073610..0x80073657  size 75 B
 * body sha256 34b52e03b027514dc88c5f02689f9272f260043fcb8c8200a8aee30ddbfbf317
 * provider record sha256 c9cb5abec661f5d235ab3fd6dd8d04349882d179eeef9ef9a01a380eee580f6a
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

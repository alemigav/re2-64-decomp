/* FUN_80073658
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80073658  body 0x80073658..0x800736a3  size 79 B
 * sha256  18c13c69c63c72f6686c652468b1741e7bdbac731d4a08caf0c6c238a69b93f4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80073658(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_80052d10(*(undefined2 *)(iVar1 + 4),*(undefined1 *)(iVar1 + 2),*(undefined1 *)(iVar1 + 3),
               *(undefined2 *)(iVar1 + 6));
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 8;
  return 1;
}

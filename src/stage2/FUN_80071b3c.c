/* FUN_80071b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80071b3c  body 0x80071b3c..0x80071b93  size 91 B
 * sha256  9df942bcd62cfcb952ec567db07743dca66270577d059ba42dffd4842cad3698
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80071b3c(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return 1;
}

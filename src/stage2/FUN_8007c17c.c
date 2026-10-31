/* FUN_8007c17c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c17c  body 0x8007c17c..0x8007c1f7  size 127 B
 * sha256  73aada269b997914f25b4c829d24ca4cadc33a33107b59be13c5e8a0ce08bfb6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c17c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b178)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

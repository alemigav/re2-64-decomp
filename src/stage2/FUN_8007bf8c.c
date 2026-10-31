/* FUN_8007bf8c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bf8c  body 0x8007bf8c..0x8007c007  size 127 B
 * sha256  8d695e9cb5788dd88bda88a2e11fcc24cf06e6ebc45ca3856636cff5387fe9a8
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bf8c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b098)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

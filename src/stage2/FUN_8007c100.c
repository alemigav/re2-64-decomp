/* FUN_8007c100
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c100  body 0x8007c100..0x8007c17b  size 127 B
 * sha256  c25eb254cf1e9940fd8fad069df32d67a84a1c74f2de8d8fed9cb9bacb4d0535
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c100(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b140)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

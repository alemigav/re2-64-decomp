/* FUN_8007bd9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bd9c  body 0x8007bd9c..0x8007be17  size 127 B
 * body sha256 b9bb64b6a52b6103cf8352641fa21f109ab71b5f1d7adae08df5e00952dd3fbc
 * provider record sha256 7ada7c76398985a41b46b555f4f9e1430f237de74f2b752fa91225f85b3091c9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bd9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011af80)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

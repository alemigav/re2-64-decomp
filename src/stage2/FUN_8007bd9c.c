/* FUN_8007bd9c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bd9c  body 0x8007bd9c..0x8007be17  size 127 B
 * sha256  5d427ddd57db1717dd2cac9451642e1a60f9b0c052b8edfafabdccd9975596ca
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bd9c(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011af80)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

/* FUN_8007c008
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c008  body 0x8007c008..0x8007c083  size 127 B
 * sha256  369b45d530e11b8e24e0ad7094af8bb0301bf8d4ca58795d5ede92a0f7d3670d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c008(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b0d0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

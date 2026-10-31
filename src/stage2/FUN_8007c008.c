/* FUN_8007c008
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c008  body 0x8007c008..0x8007c083  size 127 B
 * body sha256 e4c8a721a2045c3795e87bddf84a5c7f7e58e14ae1175b2119f47499627e9ae6
 * provider record sha256 02487c63a014af944ca43a5e49af3fa536893a011a7d07acd40d7869bad0a408
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c008(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b0d0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

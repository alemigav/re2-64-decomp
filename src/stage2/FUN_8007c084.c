/* FUN_8007c084
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c084  body 0x8007c084..0x8007c0ff  size 127 B
 * sha256  de7c0725eaa0b222bd070a51216f32659ba066606070c0fe99823bd614fb28c6
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c084(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b108)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

/* FUN_8007be18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007be18  body 0x8007be18..0x8007be93  size 127 B
 * sha256  8a55eb71a3eb50d36124d17f3c34d56edc809d6fcec3b89c1f466fb25d4903d2
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007be18(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011aff0)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

/* FUN_8007c274
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007c274  body 0x8007c274..0x8007c2ef  size 127 B
 * body sha256 8b7597c4942bd3f2ebe64b588661f60699454f9b20f1c56c4fc5713ab21fdad9
 * provider record sha256 da3f6fb5065578f098336cec95e667a610989e58b141d8c10f7ef6054c352395
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007c274(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b1e8)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

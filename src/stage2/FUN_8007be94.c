/* FUN_8007be94
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007be94  body 0x8007be94..0x8007bf0f  size 127 B
 * body sha256 aaffe16bb1e7872c9bb1e0467c197752cd5f878a4d1e6457e6ad23c51527047b
 * provider record sha256 0c96ea63cc79ed08674f5f92e79b6c235ba6987e06fd4b92dcdabef2b6243659
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007be94(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b028)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

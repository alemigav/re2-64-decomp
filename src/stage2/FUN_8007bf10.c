/* FUN_8007bf10
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007bf10  body 0x8007bf10..0x8007bf8b  size 127 B
 * sha256  b05ce3a2ea95cb1639693eed5a071c5443908b187c254b0e9b6fae168fe5e9dc
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007bf10(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b060)[*(byte *)(param_1 + 5)])();
  (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  return;
}

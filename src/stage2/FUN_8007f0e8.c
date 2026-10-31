/* FUN_8007f0e8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f0e8  body 0x8007f0e8..0x8007f17f  size 155 B
 * sha256  2253b19f27d9e203b97e727bbaf1d4d5d91b210a90f91f3181e5a9f9df5b4e31
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f0e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b2e4)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

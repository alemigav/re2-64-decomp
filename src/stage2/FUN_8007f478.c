/* FUN_8007f478
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f478  body 0x8007f478..0x8007f50f  size 155 B
 * body sha256 71a90fbb06cc6e8041c3957056d526ab5675d58d46d1a6fca23a404be947065d
 * provider record sha256 b523a994b1e05a16bacfbac9fd7d0b962a352d2218cff2f0b9d0cba8990c4b62
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f478(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b434)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

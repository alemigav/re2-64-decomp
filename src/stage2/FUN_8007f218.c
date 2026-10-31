/* FUN_8007f218
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f218  body 0x8007f218..0x8007f2af  size 155 B
 * body sha256 ed727cd1cdb191058d10a0ae056a6dd12ea26a9f6fd5277d9a1183aebdddd3a9
 * provider record sha256 6e59e1f1e11795d247d5579ff796ebfcb992383383461ef029ed467e98f7b346
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f218(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b354)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

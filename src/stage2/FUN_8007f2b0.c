/* FUN_8007f2b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f2b0  body 0x8007f2b0..0x8007f347  size 155 B
 * sha256  2e747b511003b0f2d80f0e44e93cb5a5ce967cde0f4949d1e21cdda0537c93c9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f2b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b38c)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

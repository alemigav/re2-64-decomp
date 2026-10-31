/* FUN_8007f640
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f640  body 0x8007f640..0x8007f6d7  size 155 B
 * sha256  4c4f5148450c364b6caeda1c36ee19f10c8d6cbb001ecc1a9d332fd9560ffcfc
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f640(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b4dc)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

/* FUN_8007f348
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f348  body 0x8007f348..0x8007f3df  size 155 B
 * sha256  b0ee79f903a2fc8b2ebb782b9fde32fbc90b4189828c2199305720e9eccda455
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f348(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b3c4)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

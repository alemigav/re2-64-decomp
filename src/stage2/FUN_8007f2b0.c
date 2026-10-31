/* FUN_8007f2b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f2b0  body 0x8007f2b0..0x8007f347  size 155 B
 * body sha256 4776749f45ff64c8d4c8bc0af039642bf38bba07be735c7fdcee5a4441b3830b
 * provider record sha256 e70f5f66a05419b7e0c11a169d03d0f80017572510e2c2c325dcb1712ca814a7
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

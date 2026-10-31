/* FUN_8007db38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007db38  body 0x8007db38..0x8007db6b  size 55 B
 * body sha256 6a1931baf1c104efd6dcc5d54ee0c59d03de2f1afe1a69f393d87bf43fd0ecaf
 * provider record sha256 3b9e71084db6ad313582b7be55b59835b6c2f40646a787714bff14a35e7afdc5
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007db38(int param_1)

{
  (*(code *)(&PTR_FUN_8011b28c)[*(byte *)(param_1 + 6)])();
  return;
}

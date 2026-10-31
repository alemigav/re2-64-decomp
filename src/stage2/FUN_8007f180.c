/* FUN_8007f180
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f180  body 0x8007f180..0x8007f217  size 155 B
 * sha256  27312b26bd9cfe798cb69475c194ba02cc9ba0272f595f84be404b974cb91b23
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f180(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b31c)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

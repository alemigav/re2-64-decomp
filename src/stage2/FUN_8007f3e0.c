/* FUN_8007f3e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f3e0  body 0x8007f3e0..0x8007f477  size 155 B
 * body sha256 942e29789207a4f33bc230ae03cd38e145d4db30abdf7295ceb7c6f324e01c8c
 * provider record sha256 18d24e9cd7db52b68812b52bd1c84154769d25addc0005cff1bc4853181e0841
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007f3e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  (*(code *)(&PTR_FUN_8011b3fc)[*(byte *)(param_1 + 5)])();
  if (*(char *)(param_1 + 5) == '\0') {
    FUN_8007f958(param_1,param_2,param_3);
  }
  else {
    (*(code *)(&PTR_FUN_8011afb8)[*(byte *)(param_1 + 5)])(param_1,param_2,param_3);
  }
  return;
}

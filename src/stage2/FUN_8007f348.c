/* FUN_8007f348
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007f348  body 0x8007f348..0x8007f3df  size 155 B
 * body sha256 e57a8f555745603ae0ff9a3510e640bbea128dc68617e66c5a9324baa3f576b5
 * provider record sha256 630ac78c9aca681f14193632c6753be7342d84e6f5c682b8be8cb06bdb122b73
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

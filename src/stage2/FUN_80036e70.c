/* FUN_80036e70
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80036e70  body 0x80036e70..0x80036e9f  size 51 B
 * body sha256 bbd29db3bf34c8dd0dd474f2a8ccd513778b88f724621530b04e7cb8689dfbab
 * provider record sha256 b793dc4f51d5ff22ec7a7ceeab8706cd4cc641c07af39a1a15d1d44d98d0a7b6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80036e70(int param_1)

{
  *(undefined2 *)(param_1 + 0x1d8) = 0;
  *(undefined2 *)(param_1 + 0x1da) = 0;
  *(undefined2 *)(param_1 + 0x1dc) = 0;
  FUN_80040e58(param_1 + 0x1d8,param_1 + 0x1b8);
  return;
}

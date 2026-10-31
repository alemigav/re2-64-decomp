/* FUN_8005aaf8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005aaf8  body 0x8005aaf8..0x8005ab0f  size 27 B
 * sha256  dad98084acb79acfbb060d4183eedf53e3cc227d043b6396616a3055491d6f57
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005aaf8(int param_1)

{
  *(char *)(param_1 + 0x1a3) = *(char *)(param_1 + 0x1a3) - (char)DAT_80111160;
  return;
}

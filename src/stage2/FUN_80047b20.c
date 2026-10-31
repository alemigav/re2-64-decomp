/* FUN_80047b20
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b20  body 0x80047b20..0x80047b3b  size 31 B
 * sha256  25da854440afa83f7604aa3e71080b59d2f2a7d6f92a411a025240df7f24cb6c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b20(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 7) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 7) = 2;
  return;
}

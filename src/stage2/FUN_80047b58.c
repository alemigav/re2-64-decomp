/* FUN_80047b58
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b58  body 0x80047b58..0x80047b73  size 31 B
 * sha256  c1d4690803845b2b3b0f84d67e26cc974e6aa0e3c94a3fccffc568e79d46ee82
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b58(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}

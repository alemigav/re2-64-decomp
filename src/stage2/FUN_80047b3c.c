/* FUN_80047b3c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80047b3c  body 0x80047b3c..0x80047b57  size 31 B
 * sha256  aaa7eeed1dbd5cfe241179acf39bc830318678c0ae77d68f5ca226355b17e4ad
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80047b3c(int param_1,short param_2)

{
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 3) = 0;
    return;
  }
  *(undefined1 *)(param_1 + 3) = 2;
  return;
}

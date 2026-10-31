/* FUN_800478b8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800478b8  body 0x800478b8..0x800478c3  size 15 B
 * sha256  1f55a88cfe28669b453d4b57b2ae88c0438ff79dabc74770273edd8abccd722d
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800478b8(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 4) = param_2;
  *(undefined2 *)(param_1 + 6) = param_3;
  return;
}

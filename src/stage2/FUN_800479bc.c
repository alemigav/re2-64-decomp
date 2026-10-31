/* FUN_800479bc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800479bc  body 0x800479bc..0x800479c7  size 15 B
 * sha256  9e5d0cdf7bba36be7f008a887d860e5e55d60922ad4c694a9cd74c7da83945d9
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800479bc(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  *(undefined2 *)(param_1 + 0x12) = param_3;
  return;
}

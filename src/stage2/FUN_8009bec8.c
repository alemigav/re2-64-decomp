/* FUN_8009bec8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8009bec8  body 0x8009bec8..0x8009bf03  size 63 B
 * sha256  b0d80ee6b281abe0ea497fd65e4649fbfdd2f354ff1daf6fe2978c03f4049c5f
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8009bec8(int param_1,undefined4 param_2)

{
  FUN_8009bf04();
  *(undefined4 *)(param_1 + 4) = param_2;
  FUN_8009c0c4(param_1);
  return;
}

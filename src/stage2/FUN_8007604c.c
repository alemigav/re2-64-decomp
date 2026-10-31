/* FUN_8007604c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007604c  body 0x8007604c..0x8007608b  size 67 B
 * sha256  e6f549736843b2fb18ec21ef5ef47a611f498ccbdf1d1c39b369c6b8b16af6c4
 * callees 2 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007604c(char param_1)

{
  if (param_1 == '\0') {
    FUN_800b2138(0);
  }
  else {
    FUN_800b2138(1);
  }
  func_0x80004f98(param_1 == '\0');
  return;
}

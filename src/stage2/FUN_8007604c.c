/* FUN_8007604c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007604c  body 0x8007604c..0x8007608b  size 67 B
 * body sha256 d161d8ef8fcab0d0e586fc32391c8428a996714dc48c6878cc72c80fafdee3f7
 * provider record sha256 96d7a318d348f4231791f2fca369e46b9754e736fecc6553fd050f44240a3b26
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
